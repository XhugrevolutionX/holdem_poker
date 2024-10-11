#include <iostream>
#include "player.h"
#include "table.h"

void Player::Display_cards()
{
	std::cout <<"cards : ";
	cards_[0].Display();
	std::cout << ", ";
	cards_[1].Display();
}

void Player::Display_money()
{
	std::cout << '\n' << "money : " << this->money << " $" << '\n';
}

void Player::SetCard(Card c1, Card c2)
{
	cards_.push_back(c1);
	cards_.push_back(c2);
}

void Player::SetHands(Hands hand, Value rank)
{
	hand_.hand = hand;
	hand_.ranking_value = rank;
	
}

void Player::SetName(std::string name)
{
	name_ = name;
}

void Player::SetHighCard()
{
	std::vector<Card> cards_ = this->GetCards();
	if(cards_[0].GetValue() > cards_[1].GetValue())
	{
		hand_.high_card = cards_[0].GetValue();
	}
	else
	{
		hand_.high_card = cards_[1].GetValue();
	}
}

void Player::DisplayWinningHand()
{
	std::string ranking_value;
	std::string hand;

	switch ((int)hand_.ranking_value)
	{
	case 2:
		ranking_value = "Two";
		break;
	case 3:
		ranking_value = "Three";
		break;
	case 4:
		ranking_value = "Four";
		break;
	case 5:
		ranking_value = "Five";
		break;
	case 6:
		ranking_value = "Six";
		break;
	case 7:
		ranking_value = "Seven";
		break;
	case 8:
		ranking_value = "Eight";
		break;
	case 9:
		ranking_value = "Nine";
		break;
	case 10:
		ranking_value = "Ten";
		break;
	case 11:
		ranking_value = "Jack";
		break;
	case 12:
		ranking_value = "Queen";
		break;
	case 13:
		ranking_value = "King";
		break;
	case 14:
		ranking_value = "Ace";
		break;
	}

	switch ((int)hand_.hand)
	{
	case 0:
		hand = "High Card";
		break;
	case 1:
		hand = "Pair";
		break;
	case 2:
		hand = "Two Pairs";
		break;
	case 3:
		hand = "Three of a kind";
		break;
	case 4:
		hand = "Straight";
		break;
	case 5:
		hand = "Flush";
		break;
	case 6:
		hand = "Full House";
		break;
	case 7:
		hand = "Four of a kind";
		break;
	case 8:
		hand = "Straight Flush";
		break;
	case 9:
		hand = "Royal Flush";
		break;
	}

	std::cout << hand << " by " << ranking_value << '\n';
}

void Player::Reset_cards() 
{
	cards_.clear();
	hand_.hand = Hands::kHigh_car;
	hand_.high_card = Value::kTwo;
	hand_.ranking_value = Value::kTwo;
}

void Player::Bet(Table& tab_, Player& p2, int pot_)
{
	int bet_;

	if (tab_.GetCommunityCards().size() != 0)
	{
		tab_.Display_table(pot_);
	}

	//Display bets if they aren't null
	if (p2.GetBet() != 0 && this->GetBet() != 0)
	{
		std::cout << "The other player bet " << p2.GetBet() << "$ \n";
		std::cout << "Your bet " << this->GetBet() << "$ \n\n";
	}
	else if (p2.GetBet() != 0)
	{
		std::cout << "The other player bet " << p2.GetBet() << "$ \n\n";
	}
	else if (this->GetBet() != 0)
	{
		std::cout << "Your bet " << this->GetBet() << "$ \n\n";
	}

	//Display the player cards and money
	this->Display_cards();
	this->Display_money();

	//Three cases when betting: 
	//The player doesn't have anymore money -> he needs to check
	if (this->money == 0)
	{
		std::cout << '\n' << "You don't have anymore money \n";
		std::cin >> bet_;
		while (bet_ != 0)
		{
			std::cout << '\n' << "You need to check (bet 0) \n";
			std::cin >> bet_;
		}
	}
	//The player doesn't have enought money to match to other player bet, but still has some money left -> he needs to bet all he has left 
	else if (p2.GetBet() >= this->money && this->money != 0)
	{
		std::cout << '\n' << "You need to all in \n";
		std::cin >> bet_;
		while (bet_ != this->money)
		{
			std::cout << '\n' << "Bet all you have left \n";
			std::cin >> bet_;
		}
	}
	//Neither of the above condition are met -> he can bet how much he wants between the other player bet(min) and how much money he has left(max)
	else
	{
		std::cout << '\n' << this->name_ << " enter your bet \n";
		std::cin >> bet_;

		while (!(this->GetBet() + bet_ >= p2.GetBet() && bet_ <= this->money))
		{
			if (!(this->GetBet() + bet_ >= p2.GetBet()))
			{
				std::cout << '\n' << "Your bet is too low" << '\n';
			}
			else
			{
				std::cout << '\n' << "You don't have enought money" << '\n';
			}
			std::cin >> bet_;
		}
	}


	this->money -= bet_;
	this->SetBet(bet_);
	this->SetTotalBet(bet_);

	system("cls");
	//let the time to the players to pass the pc to the opponent
	system("pause");
	system("cls");
}

void Player::SetBet(int bet_)
{
	this->bet += bet_;
}

void Player::SetTotalBet(int bet_)
{
	this->total_bet += bet_;
}

void Player::ResetTotalBet()
{
	this->total_bet = 0;
}

void Player::ResetBet()
{
	this->bet = 0;
}

void Player::Gain(Player& p2, bool draw_)
{
	int pot = (this->GetTotalBet() + p2.GetTotalBet());

	
	if (draw_)
	{
		std::cout << "Both players gains " << pot/2 << " $" << "\n\n";
		this->money += pot/2;
		p2.money += pot/2;
	}
	else 
	{
		std::cout << this->name_ << " gains " << pot << " $" << "\n\n";
		this->money += pot;
	}

	this->ResetBet();
	this->ResetTotalBet();
	p2.ResetBet();
	p2.ResetTotalBet();
}