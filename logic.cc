#include <iostream>
#include "logic.h"
#include <map>

bool Check_Flush(std::vector<Card> cards_)
{
	int counter_spades = 0;
	int counter_hearts = 0;
	int counter_clubs = 0;
	int counter_diamonds = 0;

	bool IsFlush = false;

	for (Card c : cards_)
	{
		if (c.GetSuit() == Suits::kSpades)
		{
			counter_spades++;
		}
		else if (c.GetSuit() == Suits::kHearts)
		{
			counter_hearts++;
		}
		else if (c.GetSuit() == Suits::kClubs)
		{
			counter_clubs++;
		}
		else if (c.GetSuit() == Suits::kDiamonds)
		{
			counter_diamonds++;
		}


		if (counter_spades >= 5 || counter_hearts >= 5 || counter_clubs >= 5 || counter_diamonds >= 5)
		{
			IsFlush = true;
		}
	}
	return IsFlush;

}

bool Check_Straight(std::vector<Card> cards_)
{
	bool IsStraight = false;
	std::multimap<Value, Suits> mymap;
	

	for (Card c : cards_)
	{
		mymap.insert(std::pair<Value, Suits>(c.GetValue(), c.GetSuit()));
	}
	cards_.clear();
	for (std::pair<Value,Suits> m : mymap)
	{
		Card c(m.second, m.first);
		cards_.push_back(c);
	}

	Card temp = cards_.at(0);
	cards_.pop_back();

	for (Card c : cards_)
	{
		
		if((int)c.GetValue() == (int)temp.GetValue() + 1)
		{
			IsStraight += 1;
		}
		temp = c;
	}
	if(IsStraight >= 5)
	{
		IsStraight = true;
	}

	return IsStraight;
}

//int Check_Hands(std::vector<Card> cards_)
//{
//
//	if (Check_Flush(cards_) && Check_Straight(cards_) && /* contient un As*/)
//	{
//		//Royal_Flush
//		return 0;
//	}
//	else if(Check_Flush(cards_) && Check_Straight(cards_))
//	{
//		//Straight_Flush
//		return 1;
//	}
//	else if (/*Four_of_a_Kind*/)
//	{
//		//Four_of_a_Kind
//		return 2;
//	}
//	else if (/*Full_House*/)
//	{
//		//Full_House
//		return 3;
//	}
//	else if (Check_Flush(cards_))
//	{
//		//Flush
//		return 4;
//	}
//	else if (Check_Straight(cards_))
//	{
//		//Straight
//		return 5;
//	}
//	else if (/*Three_of_a_Kind*/)
//	{
//		//Three_of_a_Kind
//		return 6;
//	}
//	else if (/*Two_Pair*/)
//	{
//		//Two_Pair
//		return 7;
//	}
//	else if (/*Pair*/)
//	{
//		//Pair
//		return 8;
//	}
//	else
//	{
//		//High_Card
//		return 9;
//	}
//	
//}


//int Check_Score(std::vector<Card> cards_)
//{
//
//}



//int Check_Win(Player &p1, Player &p2, Table &t)
//{
//	std::vector<Card> deck_p1;
//	std::vector<Card> deck_p2;
//
//	for (Card c : t.GetCommunityCards())
//	{
//		deck_p1.push_back(c);
//		deck_p2.push_back(c);
//	}
//	for (Card c : p1.GetCards())
//	{
//		deck_p1.push_back(c);
//	}
//	for (Card c : p2.GetCards())
//	{
//		deck_p2.push_back(c);
//	}
//
//	if (Check_Hands(deck_p1) > Check_Hands(deck_p2))
//	{
//		return 1;
//	}
//	else if(Check_Hands(deck_p1) < Check_Hands(deck_p2))
//	{
//		return 2;
//	}
//	else
//	{
//		if(Check_Score(deck_p1) > Check_Score(deck_p2))
//		{
//			return 1;
//		}
//		else if (Check_Score(deck_p1) < Check_Score(deck_p2))
//		{
//			return 2;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//
//}