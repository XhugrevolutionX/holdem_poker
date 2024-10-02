#ifndef LOGIC_H
#define LOGIC_H
#include "player.h"
#include "table.h"

bool Check_Color(std::vector<Card> cards_);

int Check_Win(Player& p1, Player& p2, Table& t);

int Check_Score(std::vector<Card> cards_);

int Check_Hands(std::vector<Card> cards_);






#endif // LOGIC_H
