#ifndef DECK_H
#define DECK_H

class Deck
{
private:
	std::vector<Card> deck;
public:

	Deck() = default;

	void DisplayDeck()
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

	Card PickACard()
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

	void Fill()
	{

		for (Suits s = Suits::kSpades; s <= Suits::kDiamonds; s = static_cast<Suits>(static_cast<int>(s) + 1))
		{
			for (Value v = Value::kTwo; v <= Value::kAce; v = static_cast<Value>(static_cast<int>(v) + 1))
			{
				deck.emplace_back(s, v);
			}
		}
	}

	void Shuffle()
	{
		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(deck.begin(), deck.end(), g);
	}

	void Clear()
	{
		for (auto d : deck)
		{
			deck.pop_back();
		}
	}
};
#endif // DECK_H
