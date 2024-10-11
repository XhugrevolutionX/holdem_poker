#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "hands.h"

class Table;

class Player
{
private:
	std::string name_;
	std::vector<Card> cards_;
	HandValue hand_;
	int money = 500;
	int bet = 0;
	int total_bet = 0;

public:

	Player() = default;

	Player(std::string name) : name_(name)
	{}

	void Display_cards();

	void Display_money();

	int GetMoney() { return money; }

	int GetTotalBet() { return total_bet; }

	int GetBet() { return bet; }

	void SetCard(Card c1, Card c2);

	std::vector<Card> GetCards() { return cards_; }

	HandValue GetHands() { return hand_; }

	std::string GetName() { return name_; }

	void SetName(std::string _name);

	void SetHands(Hands hand, Value rank);

	void SetHighCard();

	void DisplayWinningHand();

	void Reset_cards();

	void Bet(Table& tab_, Player& p2, int pot_);

	void SetTotalBet(int bet_);

	void SetBet(int bet_);

	void ResetBet();

	void ResetTotalBet();

	void Gain(Player& p2, bool draw_);
};

#endif // PLAYER_H
