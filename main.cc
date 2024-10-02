#include <iostream>
#include <vector>
#include <random>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "table.h"


int main()
{
	Deck deck;

	deck.Fill();
	deck.DisplayDeck();

	Card c0 = deck.PickACard();
	c0.Display();
	std::cout << '\n';

	deck.DisplayDeck();

	//deck.Fill();
	//deck.DisplayDeck();

	//deck.Shuffle();
	//deck.DisplayDeck();

	//deck.Clear();
	//deck.DisplayDeck();




	//Player player0;

	//Card c1(Suits::kClubs, Value::kTwo);
	//Card c2(Suits::kSpades, Value::kTen);

	//Player player1(c1, c2);
	//player1.Display_cards();


	//Card c3;
	//Card c4;

	//c3.Random();
	//c4.Random();

	//Player player2(c3, c4);
	//player2.Display_cards();


	//Card c5;

	//for(int i = 0; i < 20; i++)
	//{
	//	c5.Random();
	//	c5.Display();
	//}
	//std::cout << '\n';



	//Table table;

	//table.Fill();

	//table.Flop();
	//table.Turn();
	//table.River();

}