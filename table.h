#ifndef TABLE_H
#define TABLE_H

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

	void Fill()
	{
		card1_.Random();
		card2_.Random();
		card3_.Random();
		card4_.Random();
		card5_.Random();
	}

	void Flop()
	{
		card1_.Display();
		card2_.Display();
		card3_.Display();
		std::cout << '\n';
	}

	void Turn()
	{
		card4_.Display();
		std::cout << '\n';
	}

	void River()
	{
		card5_.Display();
		std::cout << '\n';
	}

};

#endif // TABLE_H
