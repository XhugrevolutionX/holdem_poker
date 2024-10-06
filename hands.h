#ifndef HANDS_H
#define HANDS_H
#include "card.h"

enum class Hands
{
	kHigh_car,
	kPair,
	kTwo_pairs,
	kThree_of_a_kind,
	kStraight,
	kFlush,
	kFull_house,
	kFour_of_a_kind,
	kStraight_flush,
	kRoyal_flush,
};

struct HandValue
{
	Hands hand;
	Value ranking_value;
	Value high_card;
};

#endif // HANDS_H
