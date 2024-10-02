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
};

#endif // TABLE_H
