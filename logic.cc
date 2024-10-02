#include <iostream>
#include "logic.h"


bool Check_Color(std::vector<Card> cards_)
{
	int compter_spades = 0;
	int compter_hearts = 0;
	int compter_clubs = 0;
	int compter_diamonds = 0;

	bool IsColor = false;

	for (Card c : cards_)
	{
		if (c.GetSuit() == Suits::kSpades)
		{
			compter_spades++;
		}
		else if (c.GetSuit() == Suits::kHearts)
		{
			compter_hearts++;
		}
		else if (c.GetSuit() == Suits::kClubs)
		{
			compter_clubs++;
		}
		else if (c.GetSuit() == Suits::kDiamonds)
		{
			compter_diamonds++;
		}


		if (compter_spades || compter_hearts || compter_clubs || compter_diamonds)
		{
			IsColor = true;
		}
	}
	return IsColor;

}

int Check_Hands(std::vector<Card> cards_)
{

	//if (/*Royal_Flush*/)
	//{
	//	//Royal_Flush
	//	return 0;
	//}
	//else if(/*Straight_Flush*/)
	//{
	//	//Straight_Flush
	//	return 1;
	//}
	//else if (/*Four_of_a_Kind*/)
	//{
	//	//Four_of_a_Kind
	//	return 2;
	//}
	//else if (/*Full_House*/)
	//{
	//	//Full_House
	//	return 3;
	//}
	//else if (/*Flush*/)
	//{
	//	//Flush
	//	return 4;
	//}
	//else if (/*Straight*/)
	//{
	//	//Straight
	//	return 5;
	//}
	//else if (/*Three_of_a_Kind*/)
	//{
	//	//Three_of_a_Kind
	//	return 6;
	//}
	//else if (/*Two_Pair*/)
	//{
	//	//Two_Pair
	//	return 7;
	//}
	//else if (/*Pair*/)
	//{
	//	//Pair
	//	return 8;
	//}
	//else
	//{
	//	//High_Card
	//	return 9;
	//}
	//
}


//int Check_Score(std::vector<Card> cards_)
//{
//
//}



int Check_Win(Player& p1, Player& p2, Table& t)
{
	std::vector<Card> deck_p1;
	std::vector<Card> deck_p2;

	for (Card c : t)
	{
		deck_p1.push_back(c);
		deck_p2.push_back(c);
	}
	for (Card c : deck_p1)
	{
		deck_p1.push_back(c);
	}
	for (Card c : deck_p2)
	{
		deck_p2.push_back(c);
	}

	if (Check_Hands(deck_p1) > Check_Hands(deck_p2))
	{
		return 1;
	}
	else if(Check_Hands(deck_p1) < Check_Hands(deck_p2))
	{
		return 2;
	}
	else
	{
		if(Check_Score(deck_p1) > Check_Score(deck_p2))
		{
			return 1;
		}
		else if (Check_Score(deck_p1) < Check_Score(deck_p2))
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}


}