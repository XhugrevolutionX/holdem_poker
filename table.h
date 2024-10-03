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
};

#endif // TABLE_H
