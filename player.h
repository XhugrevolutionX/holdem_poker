#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"

class Player
{
private:
	Card card1_;
	Card card2_;
public:

	Player() = default;

	Player(Card c1, Card c2) : card1_(c1), card2_(c2)
	{}

	void Display_cards();
};

#endif // PLAYER_H
