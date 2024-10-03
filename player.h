#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"

class Player
{
private:
	std::string name_;
	std::vector<Card> cards_;
public:

	Player() = default;

	Player(std::string name) : name_(name)
	{}

	void Display_cards();
	
	void SetCard(Card c1, Card c2);

	std::vector<Card> GetCards() { return cards_; };
};

#endif // PLAYER_H
