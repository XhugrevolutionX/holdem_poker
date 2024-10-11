#include <iostream>
#include "card.h"


void Card::Display()
{
	std::string s;
	std::string v;

	switch (suit_)
	{
	case Suits::kClubs:
		s = "Clubs";
		break;

	case Suits::kSpades:
		s = "Spades";
		break;

	case Suits::kHearts:
		s = "hearts";
		break;

	case Suits::kDiamonds:
		s = "Diamonds";
		break;
	}

	switch (value_)
	{
	case Value::kTwo:
		v = "Two";
		break;

	case Value::kThree:
		v = "Three";
		break;

	case Value::kFour:
		v = "Four";
		break;

	case Value::kFive:
		v = "Five";
		break;

	case Value::kSix:
		v = "Six";
		break;

	case Value::kSeven:
		v = "Seven";
		break;

	case Value::kEight:
		v = "Eight";
		break;

	case Value::kNine:
		v = "Nine";
		break;

	case Value::kTen:
		v = "Ten";
		break;

	case Value::kJack:
		v = "Jack";
		break;

	case Value::kQueen:
		v = "Queen";
		break;

	case Value::kKing:
		v = "King";
		break;

	case Value::kAce:
		v = "Ace";
		break;
	}

	std::cout << v << " of " << s;
}

bool Card::operator==(const Card& other)
{
	return (this->suit_ == other.suit_ && this->value_ == other.value_);
}
