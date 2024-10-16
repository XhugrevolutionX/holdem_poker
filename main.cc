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
	
	std::string Player1_name = "1";
	std::string Player2_name = "2";
	Player player1(Player1_name);
	Player player2(Player2_name);
	Deck deck;
	Table table;
	int counter = 0;
	int pot = 0;
	bool draw = false;

	//Ask players to enter their names
	std::cout << "Enter the first player's name :\n";
	std::cin >> Player1_name;
	player1.SetName(Player1_name);

	system("cls");

	std::cout << "Enter the second player's name :\n";
	std::cin >> Player2_name;
	player2.SetName(Player2_name);

	//enter game loop
	do
	{
		system("cls");

		//reset the deck, the table, and the player cards
		deck.Clear();
		table.Reset_table();
		player1.Reset_cards();
		player2.Reset_cards();


		deck.Fill();


		//Pick cards for the two players
		Card c1 = deck.PickACard();
		Card c2 = deck.PickACard();

		player1.SetCard(c1, c2);
		player1.SetHighCard();


		Card c3 = deck.PickACard();
		Card c4 = deck.PickACard();

		player2.SetCard(c3, c4);
		player2.SetHighCard();



		//Game begins with first bet
		Betting_loop(player1, player2, table, pot);
		table.Flop(deck);

		//second bet
		Betting_loop(player1, player2, table, pot);
		table.Turn(deck);

		//Third bet
		Betting_loop(player1, player2, table, pot);
		table.River(deck);

		//Last bet before the reveal
		Betting_loop(player1, player2, table, pot);




		//Display all of the cards
		table.Display_table(player1.GetTotalBet() + player2.GetTotalBet());
		std::cout << '\n' << Player1_name << "' ";
		player1.Display_cards();
		std::cout << '\n' << Player2_name << "' ";
		player2.Display_cards();
		std::cout << "\n\n";




		//After all the bets and all cards are revealed check the winner and give him the pot
		switch (Check_Win(player1, player2, table))
		{
		case 0:
			draw = true;
			std::cout << "It's a Draw, both players have : ";
			player1.DisplayWinningHand();
			player1.Gain(player2, draw);
			system("pause");
			break;
		case 1:
			draw = false;
			std::cout << Player1_name << " Wins with ";
			player1.DisplayWinningHand();
			player1.Gain(player2, draw);
			system("pause");
			break;
		case 2:
			draw = false;
			std::cout << Player2_name << " Wins with ";
			player2.DisplayWinningHand();
			player2.Gain(player1, draw);
			system("pause");
			break;
		}
	} while (player1.GetMoney() > 0 && player2.GetMoney() > 0);

	if (player1.GetMoney() == 0)
	{
		std::cout << Player1_name << " doesn't have anymore more money" << '\n';
		std::cout << "The Winner is " << Player2_name << '\n';
	}
	else
	{
		std::cout << Player2_name << " doesn't have anymore more money" << '\n';
		std::cout << "The Winner is " << Player1_name << '\n';
	}
	system("pause");
	
}