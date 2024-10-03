#include <iostream>
#include "player.h"


void Player::Display_cards()
{
	std::cout << name_ << "'s cards :\n";
	cards_[0].Display();
	cards_[1].Display();
	std::cout << '\n';
}

void Player::SetCard(Card c1, Card c2)
{
	cards_.push_back(c1);
	cards_.push_back(c2);
}