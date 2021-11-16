// P03-SumInCoins.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	double sum;
	do
	{
		std::cout << "Vavedi suma: ";
		std::cin >> sum;
	} while (sum < 0 || sum > 100);

	int sumInOneStotinki = sum * 100;
	int levs;
	int twentyStotinki;
	int fiveStotinki;
	int oneStotinki;

	levs = sumInOneStotinki / 100;
	sumInOneStotinki = sumInOneStotinki - levs * 100;

	twentyStotinki = sumInOneStotinki / 20;
	sumInOneStotinki = sumInOneStotinki - twentyStotinki * 20;

	fiveStotinki = sumInOneStotinki / 5;
	sumInOneStotinki = sumInOneStotinki - fiveStotinki * 5;

	oneStotinki = sumInOneStotinki;
	std::cout << levs << " x 1 leva + "
		<< twentyStotinki << " x 20 stotinki + "
		<< fiveStotinki << " x 5 stotinki + "
		<< oneStotinki << " x 1 stotinki"
		<< std::endl;
}
