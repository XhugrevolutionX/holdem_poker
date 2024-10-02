#include <iostream>


#include "card.h"


int main()
{


	Card c1(Suits::kClubs, Value::kTwo);
	Card c2(Suits::kSpades, Value::kTen);

	Player player1(c1, c2);
	player1.Display_cards();



	Card c3;
	Card c4;

	c3.Random();
	c4.Random();

	Player player2(c3, c4);
	player2.Display_cards();



	Card c5;

	for(int i = 0; i < 20; i++)
	{
		c5.Random();
		c5.Display();
	}
	std::cout << '\n';



	Deck deck;

	deck.fill();
	deck.DisplayDeck();

	deck.shuffle();
	deck.DisplayDeck();

	deck.Clear();
	deck.DisplayDeck();
}