#include <iostream>
#include "player.h"


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

void Player::Bet(Table& tab_)
{
	int bet_;

	if (tab_.GetCommunityCards().size() != 0)
	{
		tab_.Display_table();
	}

	this->Display_cards();
	this->Display_money();
	std::cout << '\n' << this->name_ << " enter your bet\n";
	std::cin >> bet_;

	this->money -= bet_;
	tab_.pot += bet_;

	system("cls");
	system("pause");
	system("cls");
}

void Player::Gain(Table& tab_)
{
	std::cout << this->name_ << " gains " << tab_.pot << " $" << "\n\n";
	this->money += tab_.pot;
}

void Player::Gain(Player& p2, Table& tab_)
{
	std::cout << "Both players gains " << (tab_.pot/2) << " $" << "\n\n";
	this->money += (tab_.pot / 2);
	p2.money += (tab_.pot / 2);
}