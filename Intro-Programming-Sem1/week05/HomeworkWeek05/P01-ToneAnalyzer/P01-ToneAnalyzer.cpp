// P01-ToneAnalyzer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;
int main()
{
	int firstTone;
	std::cin >> firstTone;
	int secondTone;
	std::cin >> secondTone;
	int toneSubstraction = std::abs(firstTone - secondTone);
	switch (toneSubstraction)
	{
	case 1:
	case 6:
		std::cout << "Fake sound" << endl;
		break;
	case 4:
		std::cout << "Hollow sound" << endl;
		break;
	case 2:
		std::cout << "Pleasing sound" << endl;
		break;
	default:
		std::cout << "Normal sound" << endl;
		break;
	}
}