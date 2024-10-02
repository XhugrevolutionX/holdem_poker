#include <iostream>
#include "deck.h"

Card Deck::PickACard()
{
	
	Card card;
	bool card_is_in_deck = false;
	do
	{
		card.Random();

		auto it = std::find(deck.begin(), deck.end(), card);

		// If element is found found, erase it
		if (it != deck.end()) {
			card_is_in_deck = true;
			deck.erase(it);
			return card;
		}
	} while (!card_is_in_deck);
}

void Deck::DisplayDeck()
{

	if (deck.empty())
	{
		std::cout << "The deck is empty \n";
	}
	else
	{
		std::vector<Card> deck_copy;
		for (auto d : deck)
		{
			deck_copy.emplace_back(d);
			d.Display();
			deck.pop_back();
		}
		deck = deck_copy;
		std::cout << "\n";
	}

}
