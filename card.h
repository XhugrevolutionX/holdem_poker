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

class Deck
{

private:
	std::vector<Card> deck;
public:
	Deck() = default;

	void DisplayDeck()
	{

		if(deck.empty())
		{
			std::cout << "The deck is empty \n";
		}
		else
		{
			std::vector<Card> deck_copy;
			for (auto d : deck)
			{
				deck_copy.emplace_back(d);
				d.Display();
				deck.pop_back();
			}
			deck = deck_copy;
			std::cout << "\n";
		}

	}

	void fill()
	{
		
		for (Suits s = Suits::kSpades; s <= Suits::kDiamonds; s = static_cast<Suits>(static_cast<int>(s) + 1))
		{
			for(Value v = Value::kTwo; v <= Value::kAce; v = static_cast<Value>(static_cast<int>(v) + 1))
			{
				deck.emplace_back(s,v);
			}
		}
	}

	void shuffle()
	{
		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(deck.begin(), deck.end(), g);
	}
	
	void Clear()
	{
		for (auto d : deck)
		{
			deck.pop_back();
		}
	}


};

class Player
{

private:
	Card card1_;
	Card card2_;
public:
	
	//Player();
	

	Player(Card c1, Card c2) : card1_(c1), card2_(c2)
	{
	}

	void Display_cards()
	{
		card1_.Display();
		card2_.Display();
		std::cout << '\n';
	}

	//void TakeCards(Card new_card1, Card new_card2)
	//{
	//	card1_ = new_card1;
	//	card2_ = new_card2;
	//}
};

class Table
{


private:
	Card card1_;
	Card card2_;
	Card card3_;
	Card card4_;
	Card card5_;
public:

	void Flop()
	{}

	void Turn()
	{}

	void River()
	{}

};

#endif // CARD_H
