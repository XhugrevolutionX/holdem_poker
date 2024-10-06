#include <iostream>
#include "player.h"


void Player::Display_cards()
{
	std::cout << name_ << "'s cards :\n";
	cards_[0].Display();
	cards_[1].Display();
	std::cout << '\n';
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

void Player::DisplayHand()
{
	std::string high_card;
	std::string ranking_value;
	std::string hand;

	switch ((int)hand_.high_card)
	{
	case 2:
		high_card = "Two";
		break;
	case 3:
		high_card = "Three";
		break;
	case 4:
		high_card = "Four";
		break;
	case 5:
		high_card = "Five";
		break;
	case 6:
		high_card = "Six";
		break;
	case 7:
		high_card = "Seven";
		break;
	case 8:
		high_card = "Eight";
		break;
	case 9:
		high_card = "Nine";
		break;
	case 10:
		high_card = "Ten";
		break;
	case 11:
		high_card = "Jack";
		break;
	case 12:
		high_card = "Queen";
		break;
	case 13:
		high_card = "King";
		break;
	case 14:
		high_card = "Ace";
		break;
	}

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

	std::cout << "High Card between the two in Hand : " << high_card << '\n' << "High Card in the hand played : " << ranking_value << '\n' << "Hand played : " << hand;
}