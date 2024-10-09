#include <iostream>
#include "table.h"


Table::Table()
{
	community_cards_.reserve(5);
}

void Table::Flop(Deck& deck_)
{
	community_cards_.push_back(deck_.PickACard());
	community_cards_.push_back(deck_.PickACard());
	community_cards_.push_back(deck_.PickACard());

}

void Table::Turn(Deck& deck_)
{
	deck_.Burn();
	community_cards_.push_back(deck_.PickACard());

}

void Table::River(Deck& deck_)
{
	deck_.Burn();
	community_cards_.push_back(deck_.PickACard());

}

void Table::FillTable(Card C1, Card C2, Card C3, Card C4, Card C5)
{
	community_cards_.push_back(C1);
	community_cards_.push_back(C2);
	community_cards_.push_back(C3);
	community_cards_.push_back(C4);
	community_cards_.push_back(C5);
}

void Table::Display_table()
{
	for (int i = 0; i < community_cards_.size(); i++)
	{
		community_cards_[i].Display();
	}
	std::cout << '\n';
}

void Table::Destroy_table()
{
	community_cards_.clear();
}