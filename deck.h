#ifndef DECK_H
#define DECK_H

#include "card.h"

class Deck
{
private:
	std::vector<Card> deck;
public:

	Deck() = default;

	void DisplayDeck();

	Card PickACard();

	void Fill();

	void Shuffle();

	void Clear();
};
#endif // DECK_H
