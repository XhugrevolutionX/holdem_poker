#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "hands.h"
#include "table.h"

class Player
{
private:
	std::string name_;
	std::vector<Card> cards_;
	HandValue hand_;
	int money = 500;
public:

	Player() = default;

	Player(std::string name) : name_(name)
	{}

	void Display_cards();

	void Display_money();

	int GetMoney() { return money; }
	
	void SetCard(Card c1, Card c2);

	std::vector<Card> GetCards() { return cards_; }

	HandValue GetHands() { return hand_; }

	std::string GetName() { return name_; }

	void SetName(std::string _name);

	void SetHands(Hands hand, Value rank);

	void SetHighCard();

	void DisplayWinningHand();

	void Reset_cards();

	void Bet(Table& tab_);

	void Gain(Table& tab_);

	void Gain(Player& p2, Table& tab_);
};

#endif // PLAYER_H
