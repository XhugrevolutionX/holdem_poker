#ifndef TABLE_H
#define TABLE_H

#include "card.h"
#include "deck.h"

class Table
{
private:
	std::vector<Card> community_cards_;
public:

	Table();

	void Flop(Deck& deck_);

	void Turn(Deck& deck_);

	void River(Deck& deck_);

	std::vector<Card> GetCommunityCards() { return community_cards_; }

	void FillTable(Card C1, Card C2, Card C3, Card C4, Card C5);

	void Display_table();

	void Destroy_table();
};

#endif // TABLE_H
