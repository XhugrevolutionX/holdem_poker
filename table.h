#ifndef TABLE_H
#define TABLE_H

#include "card.h"
#include "deck.h"

class Table
{
private:
	Card card1_;
	Card card2_;
	Card card3_;
	Card card4_;
	Card card5_;
public:

	Table() = default;

	void Flop(Deck& deck_);

	void Turn(Deck& deck_);

	void River(Deck& deck_);
};

#endif // TABLE_H
