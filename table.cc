#include <iostream>
#include "table.h"


Table::Table()
{
	community_cards_.reserve(5);
}

void Table::Flop(Deck& deck_)
{

	deck_.Burn();
	community_cards_.push_back(deck_.PickACard());
	community_cards_[0].Display();
	community_cards_.push_back(deck_.PickACard());
	community_cards_[1].Display();
	community_cards_.push_back(deck_.PickACard());
	community_cards_[2].Display();
	std::cout << '\n';
}

void Table::Turn(Deck& deck_)
{
	deck_.Burn();
	community_cards_.push_back(deck_.PickACard());
	community_cards_[3].Display();
	std::cout << '\n';
}

void Table::River(Deck& deck_)
{
	deck_.Burn();
	community_cards_.push_back(deck_.PickACard());
	community_cards_[4].Display();
	std::cout << '\n';
}