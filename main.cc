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

	deck.Fill();


	Card c1 = deck.PickACard();
	Card c2 = deck.PickACard();

	player1.SetCard(c1, c2);
	player1.SetHighCard();


	Card c3 = deck.PickACard();
	Card c4 = deck.PickACard();

	player2.SetCard(c3, c4);
	player2.SetHighCard();


	table.Flop(deck);
	table.Turn(deck);
	table.River(deck);

	player1.Display_cards();
	player2.Display_cards();

	switch (Check_Win(player1, player2, table))
	{
	case 0:
		std::cout << "It's a Draw\n";
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


	//---------------------------
	//function verification

	//Card
	//	C1(Suits::kHearts, Value::kAce),
	//	C2(Suits::kHearts, Value::kKing),
	//	C3(Suits::kHearts, Value::kJack),
	//	C4(Suits::kHearts, Value::kTen),
	//	C5(Suits::kHearts, Value::kQueen),
	//	C6(Suits::kClubs, Value::kSeven),
	//	C7(Suits::kSpades, Value::kEight);


	//Player player0("Hugo");
	//Table t;

	//player0.SetCard(C1, C2);
	//player0.SetHighCard();
	//t.FillTable(C3, C4, C5, C6, C7);

	//Check_Hands(player0, t);

	//player0.DisplayHand();
	//------------------------------
}


/*

		Royal Flush
		C1(Suits::kHearts, Value::kAce),
		C2(Suits::kHearts, Value::kKing),
		C3(Suits::kHearts, Value::kJack),
		C4(Suits::kHearts, Value::kTen),
		C5(Suits::kHearts, Value::kQueen),
		C6(Suits::kClubs, Value::kSeven),
		C7(Suits::kSpades, Value::kEight);

		Straight Flush
		C1(Suits::kHearts, Value::kTwo),
		C2(Suits::kHearts, Value::kThree),
		C3(Suits::kHearts, Value::kFour),
		C4(Suits::kHearts, Value::kFive),
		C5(Suits::kHearts, Value::kSix),
		C6(Suits::kHearts, Value::kSeven),
		C7(Suits::kHearts, Value::kEight);

		Four of a kind
		C1(Suits::kClubs, Value::kTen),
		C2(Suits::kHearts, Value::kTen),
		C3(Suits::kDiamonds, Value::kTen),
		C4(Suits::kSpades, Value::kTen),
		C5(Suits::kHearts, Value::kQueen),
		C6(Suits::kClubs, Value::kSeven),
		C7(Suits::kSpades, Value::kEight);

		Full House
		C1(Suits::kClubs, Value::kTen),
		C2(Suits::kHearts, Value::kTen),
		C3(Suits::kDiamonds, Value::kTen),
		C4(Suits::kSpades, Value::kNine),
		C5(Suits::kHearts, Value::kNine),
		C6(Suits::kClubs, Value::kSeven),
		C7(Suits::kSpades, Value::kEight);

		Flush
		C1(Suits::kHearts, Value::kTwo),
		C2(Suits::kHearts, Value::kSeven),
		C3(Suits::kHearts, Value::kFour),
		C4(Suits::kHearts, Value::kJack),
		C5(Suits::kHearts, Value::kSix),
		C6(Suits::kClubs, Value::kSeven),
		C7(Suits::kSpades, Value::kEight);

		Straight
		C1(Suits::kSpades, Value::kTwo),
		C2(Suits::kDiamonds, Value::kThree),
		C3(Suits::kClubs, Value::kFour),
		C4(Suits::kHearts, Value::kFive),
		C5(Suits::kDiamonds, Value::kSix),
		C6(Suits::kClubs, Value::kSeven),
		C7(Suits::kSpades, Value::kEight);

		Three of a kind
		C1(Suits::kClubs, Value::kAce),
		C2(Suits::kHearts, Value::kTen),
		C3(Suits::kDiamonds, Value::kTen),
		C4(Suits::kSpades, Value::kTen),
		C5(Suits::kHearts, Value::kSix),
		C6(Suits::kClubs, Value::kSeven),
		C7(Suits::kSpades, Value::kEight);

		Two Pair
		C1(Suits::kClubs, Value::kAce),
		C2(Suits::kHearts, Value::kTen),
		C3(Suits::kDiamonds, Value::kTen),
		C4(Suits::kSpades, Value::kSix),
		C5(Suits::kHearts, Value::kSix),
		C6(Suits::kClubs, Value::kSeven),
		C7(Suits::kSpades, Value::kEight);

		Pair
		C1(Suits::kClubs, Value::kAce),
		C2(Suits::kHearts, Value::kTen),
		C3(Suits::kDiamonds, Value::kTen),
		C4(Suits::kSpades, Value::kTwo),
		C5(Suits::kHearts, Value::kSix),
		C6(Suits::kClubs, Value::kSeven),
		C7(Suits::kSpades, Value::kEight);

		High Card
		C1(Suits::kClubs, Value::kAce),
		C2(Suits::kHearts, Value::kTen),
		C3(Suits::kDiamonds, Value::kQueen),
		C4(Suits::kSpades, Value::kTwo),
		C5(Suits::kHearts, Value::kSix),
		C6(Suits::kClubs, Value::kSeven),
		C7(Suits::kSpades, Value::kEight);

 */