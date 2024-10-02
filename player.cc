#include <iostream>
#include "player.h"


void Player::Display_cards()
{
	card1_.Display();
	card2_.Display();
	std::cout << '\n';
}