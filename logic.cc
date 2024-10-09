#include <iostream>
#include "logic.h"
#include <map>

bool Check_Flush(Player &p, Table &t)
{
	std::vector<Card> deck_p;
	Value High_card;
	std::map<Suits, Value> highmap;
	std::map<Suits, int> countmap;
	bool IsFlush = false;

	countmap[Suits::kClubs] = 0;
	countmap[Suits::kDiamonds] = 0;
	countmap[Suits::kSpades] = 0;
	countmap[Suits::kHearts] = 0;


	for (Card c : t.GetCommunityCards())
	{
		deck_p.push_back(c);
	}
	for (Card c : p.GetCards())
	{
		deck_p.push_back(c);
	}

	for (Card c : deck_p)
	{
		countmap[c.GetSuit()] = countmap[c.GetSuit()] + 1;

		if(highmap.find(c.GetSuit()) != highmap.end())
		{
			if (highmap[c.GetSuit()] < c.GetValue())
			{
				highmap[c.GetSuit()] = c.GetValue();
			}
		}
		else
		{
			highmap[c.GetSuit()] = c.GetValue();
		}

		if (countmap[Suits::kClubs] >= 5)
		{
			IsFlush = true;

			High_card = highmap[Suits::kClubs];
		}
		else if(countmap[Suits::kHearts] >= 5)
		{
			IsFlush = true;
			High_card = highmap[Suits::kHearts];
		}
		else if (countmap[Suits::kSpades] >= 5)
		{
			IsFlush = true;
			High_card = highmap[Suits::kSpades];
		}
		else if (countmap[Suits::kDiamonds] >= 5)
		{
			IsFlush = true;
			High_card = highmap[Suits::kDiamonds];
		}
	}
	if (IsFlush)
	{
		p.SetHands(Hands::kFlush, High_card);
	}
	return IsFlush;
}

bool Check_Straight(Player &p, Table &t)
{

	std::vector<Card> deck_p;
	bool IsStraight = false;
	int counterStraight = 0;
	std::multimap<Value, Suits> mymap;
	Value High_card;


	for (Card c : t.GetCommunityCards())
	{
		mymap.insert(std::pair<Value, Suits>(c.GetValue(), c.GetSuit()));
	}
	for (Card c : p.GetCards())
	{
		mymap.insert(std::pair<Value, Suits>(c.GetValue(),c.GetSuit()));
	}

	for (std::pair<Value,Suits> m : mymap)
	{
		Card c(m.second, m.first);
		deck_p.push_back(c);
	}

	Card temp = deck_p[0];
	deck_p.erase(deck_p.begin());

	for (Card c : deck_p)
	{
		
		if((int)c.GetValue() == (int)temp.GetValue() + 1)
		{
			counterStraight += 1;
			High_card = c.GetValue();
		}
		else 
		{
			if (counterStraight != 0 && counterStraight < 4)
			{
				counterStraight = 0;
			}
		}

		temp = c;
	}
	if(counterStraight >= 4)
	{
		IsStraight = true;
		p.SetHands(Hands::kStraight, High_card);
	}

	return IsStraight;
}

bool Check_as_an_Ace(Player &p, Table &t)
{
	std::vector<Card> deck_p;

	for (Card c : t.GetCommunityCards())
	{
		deck_p.push_back(c);
	}
	for (Card c : p.GetCards())
	{
		deck_p.push_back(c);
	}

	bool as_an_ace = false;
	for (Card c : deck_p)
	{
		if((int)c.GetValue() == 14)
		{
			as_an_ace = true;
		}
	}
	return as_an_ace;
}


bool Check_Royal_Flush(Player& p, Table& t)
{
	std::vector<Card> deck_p;
	bool IsRoyal_flush = false;
	int counterRoyal_flush = 0;
	std::multimap<Value, Suits> mymap;
	Value High_card;


	for (Card c : t.GetCommunityCards())
	{
		mymap.insert(std::pair<Value, Suits>(c.GetValue(), c.GetSuit()));
	}
	for (Card c : p.GetCards())
	{
		mymap.insert(std::pair<Value, Suits>(c.GetValue(), c.GetSuit()));
	}

	for (std::pair<Value, Suits> m : mymap)
	{
		Card c(m.second, m.first);
		deck_p.push_back(c);
	}

	Card temp = deck_p[0];
	deck_p.erase(deck_p.begin());

	for (Card c : deck_p)
	{

		if ((int)c.GetValue() == (int)temp.GetValue() + 1 && c.GetSuit() == temp.GetSuit())
		{
			counterRoyal_flush += 1;
			High_card = c.GetValue();
		}
		else
		{
			if (counterRoyal_flush != 0 && counterRoyal_flush < 4)
			{
				counterRoyal_flush = 0;
			}
		}

		temp = c;
	}
	if (counterRoyal_flush >= 4 && High_card == Value::kAce)
	{
		IsRoyal_flush = true;
		p.SetHands(Hands::kRoyal_flush, High_card);
	}

	return IsRoyal_flush;
}

bool Check_Straight_Flush(Player& p, Table& t)
{
	std::vector<Card> deck_p;
	bool IsStraight_flush = false;
	int counterStraight_flush = 0;
	std::multimap<Value, Suits> mymap;
	Value High_card;


	for (Card c : t.GetCommunityCards())
	{
		mymap.insert(std::pair<Value, Suits>(c.GetValue(), c.GetSuit()));
	}
	for (Card c : p.GetCards())
	{
		mymap.insert(std::pair<Value, Suits>(c.GetValue(), c.GetSuit()));
	}

	for (std::pair<Value, Suits> m : mymap)
	{
		Card c(m.second, m.first);
		deck_p.push_back(c);
	}

	Card temp = deck_p[0];
	deck_p.erase(deck_p.begin());

	for (Card c : deck_p)
	{

		if ((int)c.GetValue() == (int)temp.GetValue() + 1 && c.GetSuit() == temp.GetSuit())
		{
			counterStraight_flush += 1;
			High_card = c.GetValue();
		}
		else
		{
			if (counterStraight_flush != 0 && counterStraight_flush < 4)
			{
				counterStraight_flush = 0;
			}
		}

		temp = c;
	}
	if (counterStraight_flush >= 4)
	{
		IsStraight_flush = true;
		p.SetHands(Hands::kStraight_flush, High_card);
	}

	return IsStraight_flush;
}

void Check_same_cards(Player &p, Table &t)
{

	std::multimap<Value, Suits> mymap;
	std::map<Value, int> occurences;
	std::vector<Card> deck_p;
	std::vector<Value> used_cards;

	int nb_pair = 0;
	bool isThree_of_a_kind = false;
	bool isFour_of_a_kind = false;



	for (Card c : t.GetCommunityCards())
	{
		mymap.insert(std::pair<Value, Suits>(c.GetValue(), c.GetSuit()));
	}
	for (Card c : p.GetCards())
	{
		mymap.insert(std::pair<Value, Suits>(c.GetValue(), c.GetSuit()));
	}

	for (std::pair<Value, Suits> m : mymap)
	{
		Card c(m.second, m.first);
		deck_p.push_back(c);
	}

	for (Card c : deck_p)
	{
		occurences[c.GetValue()]++;
	}


	for (auto entry : occurences)
	{
		if(entry.second >= 2)
		{
			nb_pair++;
			used_cards.push_back(entry.first);
		}
		if(entry.second >= 3)
		{
			isThree_of_a_kind = true;
			used_cards.push_back(entry.first);
		}
		if (entry.second == 4)
		{
			isFour_of_a_kind = true;
			used_cards.push_back(entry.first);
		}
	}

	if(nb_pair != 0 || isFour_of_a_kind == true || isThree_of_a_kind == true)
	{
		Value High_card = used_cards[0];
		used_cards.erase(used_cards.begin());

		for (Value v : used_cards)
		{
			if (v > High_card)
			{
				High_card = v;
			}
		}

		if (isFour_of_a_kind)
		{
			p.SetHands(Hands::kFour_of_a_kind, High_card);
		}
		else if (nb_pair == 2 && isThree_of_a_kind)
		{
			p.SetHands(Hands::kFull_house, High_card);
		}
		else if (isThree_of_a_kind)
		{
			p.SetHands(Hands::kThree_of_a_kind, High_card);
		}
		else if (nb_pair >= 2)
		{
			p.SetHands(Hands::kTwo_pairs, High_card);
		}
		else if (nb_pair == 1 && !isThree_of_a_kind)
		{
			p.SetHands(Hands::kPair, High_card);
		}
	}
}

void High_card(Player& p, Table& t)
{
	std::vector<Card> deck_p;

	for (Card c : t.GetCommunityCards())
	{
		deck_p.push_back(c);
	}
	for (Card c : p.GetCards())
	{
		deck_p.push_back(c);
	}

	Value high_card = deck_p[0].GetValue();
	deck_p.erase(deck_p.begin());
	for (Card c : deck_p)
	{
		if(c.GetValue() > high_card)
		{
			high_card = c.GetValue();
		}
	}
	p.SetHands(Hands::kHigh_car, high_card);
}



int Check_Hands(Player &p, Table &t)
{
	if (Check_Royal_Flush(p,t))
	{
		//Royal_Flush
		return 0;
	}
	else if(Check_Straight_Flush(p,t))
	{
		//Straight_Flush
		return 1;
	}
	else
	{
		Check_same_cards(p, t);
		if (p.GetHands().hand == Hands::kFour_of_a_kind)
		{
			//Four_of_a_Kind
			return 2;
		}
		else if (p.GetHands().hand == Hands::kFull_house)
		{
			//Full_House
			return 3;
		}
		else
		{
			if (Check_Flush(p, t))
			{
				//Flush
				return 4;
			}
			else if (Check_Straight(p, t))
			{
				//Straight
				return 5;
			}
			else
			{
				Check_same_cards(p, t);
				if (p.GetHands().hand == Hands::kThree_of_a_kind)
				{
					//Three_of_a_Kind
					return 6;
				}
				else if (p.GetHands().hand == Hands::kTwo_pairs)
				{
					//Two_Pair
					return 7;
				}
				else if (p.GetHands().hand == Hands::kPair)
				{
					//Pair
					return 8;
				}
				else
				{
					//High_Card
					High_card(p, t);
					return 9;
				}
			}
		}
	}
}


int Check_Win(Player &p1, Player &p2, Table &t)
{
	if (Check_Hands(p1,t) < Check_Hands(p2,t))
	{
		return 1;
	}
	else if(Check_Hands(p1, t) > Check_Hands(p2, t))
	{
		return 2;
	}
	else
	{
		if(p1.GetHands().ranking_value > p2.GetHands().ranking_value)
		{
			return 1;
		}
		else if (p2.GetHands().ranking_value > p1.GetHands().ranking_value)
		{
			return 2;
		}
		else
		{
			if (p1.GetHands().high_card > p2.GetHands().high_card)
			{
				return 1;
			}
			else if (p2.GetHands().high_card > p1.GetHands().high_card)
			{
				return 2;
			}
			else
			{
				return 0;
			}
		}
	}
}