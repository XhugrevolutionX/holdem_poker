#ifndef LOGIC_H
#define LOGIC_H
#include "player.h"
#include "table.h"

bool Check_Flush(Player& p, Table& t);

bool Check_Straight(Player& p, Table& t);

bool Check_as_an_Ace(Player& p, Table& t);

void Check_Pair(Player& p, Table& t);

//int Check_Win(Player& p1, Player& p2, Table& t);

int Check_Hands(Player &p, Table &t);






#endif // LOGIC_H
