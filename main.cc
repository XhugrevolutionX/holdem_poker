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
	Player player1("Player1_name");
	Player player2("Player2_name");
	Deck deck;
	Table table;
	int counter = 0;


	deck.DestroyDeck();
	table.Destroy_table();
	player1.Player_reset();
	player2.Player_reset();



	std::cout << "Enter the first player's name :\n";
	std::string Player1_name;
	std::cin >> Player1_name;
	player1.SetName(Player1_name);

	std::cout << "Enter the second player's name :\n";
	std::string Player2_name;
	std::cin >> Player2_name;
	player2.SetName(Player2_name);

	system("cls");

	deck.Fill();


	Card c1 = deck.PickACard();
	Card c2 = deck.PickACard();

	player1.SetCard(c1, c2);
	player1.SetHighCard();
	player1.Display_cards();
	system("pause");
	system("cls");

	Card c3 = deck.PickACard();
	Card c4 = deck.PickACard();

	player2.SetCard(c3, c4);
	player2.SetHighCard();
	player2.Display_cards();


	//first bet
	system("pause");
	system("cls");


	table.Flop(deck);
	table.Display_table();
	//Second bet
	system("pause");
	system("cls");


	table.Turn(deck);
	table.Display_table();
	//Third bet
	system("pause");
	system("cls");


	table.River(deck);
	table.Display_table();
	// Fourth bet
	system("pause");
	system("cls");



	switch (Check_Win(player1, player2, table))
	{
	case 0:
		std::cout << "It's a Draw\n";
		break;
	case 1:
		std::cout << Player1_name << " Wins with :\n";
		player1.DisplayHand();
		player2.DisplayHand();
		break;
	case 2:
		std::cout << Player2_name << " Wins with :\n";
		player2.DisplayHand();
		player1.DisplayHand();
		break;
	}
}