#include <iostream>
#include "table.h"


void Table::Fill()
{
	card1_.Random();
	card2_.Random();
	card3_.Random();
	card4_.Random();
	card5_.Random();
}

void Table::Flop()
{
	card1_.Display();
	card2_.Display();
	card3_.Display();
	std::cout << '\n';
}

void Table::Turn()
{
	card4_.Display();
	std::cout << '\n';
}

void Table::River()
{
	card5_.Display();
	std::cout << '\n';
}