#ifndef CARD_H
#define CARD_H

#include <vector>
#include <random>

enum class Suits
{
	kSpades,
	kHearts,
	kClubs,
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
	Card() = default;

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

	void Random()
	{

		int s;
		int v;
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> Suits_distr(0, 3); // define the range
		std::uniform_int_distribution<> Value_distr(2, 14); // define the range

		for (int n = 0; n < 40; ++n)
			suit_ = static_cast<Suits>(Suits_distr(gen)); // generate numbers
			value_ = static_cast<Value>(Value_distr(gen)); // generate numbers
	}
};

#endif // CARD_H
