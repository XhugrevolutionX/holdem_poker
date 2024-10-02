#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	Card card1_;
	Card card2_;
public:

	//Player();

	Player(Card c1, Card c2) : card1_(c1), card2_(c2)
	{
	}

	void Display_cards()
	{
		card1_.Display();
		card2_.Display();
		std::cout << '\n';
	}

	//void TakeCards(Card new_card1, Card new_card2)
	//{
	//	card1_ = new_card1;
	//	card2_ = new_card2;
	//}
};

#endif // PLAYER_H
