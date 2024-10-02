#include <iostream>
#include <vector>
#include <random>
#include "deck.h"
#include "card.h"
#include "player.h"
#include "table.h"
#include "logic.h"


int main()
{
	int win = 0;

	std::cout << "Enter the first player's name :\n";
	std::string Player1_name;
	std::cin >> Player1_name;

	std::cout << "Enter the second player's name :\n";
	std::string Player2_name;
	std::cin >> Player2_name;



	Deck deck;

	deck.Fill();
	deck.DisplayDeck();



	Card c1 = deck.PickACard();
	Card c2 = deck.PickACard();

	Player player1(Player1_name);
	player1.GetCard(c1, c2);
	player1.Display_cards();



	Card c3 = deck.PickACard();
	Card c4 = deck.PickACard();

	Player player2(Player2_name);
	player2.GetCard(c3, c4);
	player2.Display_cards();

	deck.DisplayDeck();



	Table table;

	table.Flop(deck);
	table.Turn(deck);
	table.River(deck);

	deck.DisplayDeck();


	Check_Win(player1, player2, table);

	switch (win)
	{
	case 0:
		std::cout << "It's a Draw\n";
		case 1:
			std::cout << Player1_name << " wins\n";
		case 2:
			std::cout << Player2_name << " wins\n";
	}


}