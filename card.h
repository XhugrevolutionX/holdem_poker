#ifndef CARD_H
#define CARD_H

#include <vector>
#include <random>

enum class Suits
{
	kClubs,
	kSpades,
	kHearts,
	kDiamonds,
};

enum class Value
{
	kTwo = 2,
	kThree,
	kFour,
	kFive,
	kSix,
	kSeven,
	kEight,
	kNine,
	kTen,
	kJack,
	kQueen,
	kKing,
	kAce,
};

class Card
{

private:
	Suits suit_;
	Value value_;

public:
	Card(Suits s, Value v) : suit_(s), value_(v)
	{
	}
	void Display()
	{
		std::string s;
		std::string v;

		switch(suit_)
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

		std::cout << v << " of " << s << '\n';
	}
};

class Deck
{

private:
	std::vector<Card> deck;

public:
	Deck() = default;

	void DisplayDeck()
	{
		for (auto d : deck)
		{
			d.Display();
			deck.pop_back();
		}
	}

	void fill()
	{
		for (Value v = Value::kTwo; v < Value::kAce; v = static_cast<Value>(static_cast<int>(v) + 1))
		{
			for(Suits s = Suits::kClubs; s < Suits::kDiamonds; s = static_cast<Suits>(static_cast<int>(s) + 1))
			{
				deck.emplace_back(s,v);
			}
		}

	}
	/*
	void shuffle()
	{
		std::random_device rd;
		std::mt19937 g(rd);

		std::shuffle(deck.begin(), deck.end(), g);
	}


	void Clear()
	{

	}
	*/


};

class Player
{

private:
	Card card1;
	Card card2;

public:
	Player();

	void TakeCards(Card new_card1, Card new_card2)
	{
		card1 = new_card1;
		card2 = new_card2;
	}
};


#endif // CARD_H
