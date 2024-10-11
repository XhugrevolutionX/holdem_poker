#ifndef CARD_H
#define CARD_H
#include <vector>
#include <random>

enum class Suits
{
	kSpades = 0,
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
	{}

	Suits GetSuit() { return suit_; }

	Value GetValue() { return value_; }

	void Display();

	bool operator==(const Card& other);
};
#endif // CARD_H
