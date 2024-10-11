#include <iostream>
#include "deck.h"


void Deck::Shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(deck.begin(), deck.end(), g);
}

Card Deck::PickACard()
{
	Card card;
	card = deck[0];
	deck.erase(deck.begin());
	return card;
}

void Deck::DisplayDeck()
{
	std::cout << deck.size() << '\n';

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
			std::cout << "\n";
		}
		deck = deck_copy;

	}

}

void Deck::Fill()
{

	for (Suits s = Suits::kSpades; s <= Suits::kDiamonds; s = static_cast<Suits>(static_cast<int>(s) + 1))
	{
		for (Value v = Value::kTwo; v <= Value::kAce; v = static_cast<Value>(static_cast<int>(v) + 1))
		{
			deck.emplace_back(s, v);
		}
	}
	this->Shuffle();
}

void Deck::Clear()
{
	for (auto d : deck)
	{
		deck.pop_back();
	}
}

void Deck::Burn()
{
	deck.pop_back();
}