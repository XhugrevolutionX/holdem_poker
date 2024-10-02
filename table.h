#ifndef TABLE_H
#define TABLE_H

#include "card.h"

class Table
{
private:
	Card card1_;
	Card card2_;
	Card card3_;
	Card card4_;
	Card card5_;
public:

	Table() = default;

	void Fill();

	void Flop();

	void Turn();

	void River();
};

#endif // TABLE_H
