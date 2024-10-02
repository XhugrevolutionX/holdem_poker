#include <iostream>
#include "table.h"

void Table::Flop(Deck& deck_)
{

	deck_.Burn();
	card1_ = deck_.PickACard();
	card1_.Display();
	card2_ = deck_.PickACard();
	card2_.Display();
	card3_ = deck_.PickACard();
	card3_.Display();
	std::cout << '\n';
}

void Table::Turn(Deck& deck_)
{
	deck_.Burn();
	card4_ = deck_.PickACard();
	card4_.Display();
	std::cout << '\n';
}

void Table::River(Deck& deck_)
{
	deck_.Burn();
	card5_ = deck_.PickACard();
	card5_.Display();
	std::cout << '\n';
}