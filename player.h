#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "hands.h"

class Player
{
private:
	std::string name_;
	std::vector<Card> cards_;
	HandValue hand_;
public:

	Player() = default;

	Player(std::string name) : name_(name)
	{}

	void Display_cards();
	
	void SetCard(Card c1, Card c2);

	std::vector<Card> GetCards() { return cards_; }

	HandValue GetHands() { return hand_; }

	std::string GetName() { return name_; }

	void SetName(std::string _name);

	void SetHands(Hands hand, Value rank);

	void SetHighCard();

	void DisplayHand();

	void Player_reset();
};

#endif // PLAYER_H
