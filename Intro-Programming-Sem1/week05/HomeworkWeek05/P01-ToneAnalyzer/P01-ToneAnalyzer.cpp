// P01-ToneAnalyzer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;
int main()
{
	int firstTone;
	int	firstOctave;
	std::cout << "Vavedi parvi ton: ";
	std::cin >> firstTone;
	std::cout << "Vavedi negovata oktava: ";
	std::cin >> firstOctave;


	int secondTone;
	int secondOctave;
	std::cout << "Vavedi vtori ton: ";
	std::cin >> secondTone;
	std::cout << "Vavedi negovata ton: ";
	std::cin >> secondOctave;

	std::cout << (firstTone + firstOctave * 7) << std::endl;
	std::cout << (secondTone + secondOctave * 7) << std::endl;

	int toneDistance = ((firstTone + firstOctave * 7) - (secondTone + secondOctave * 7)) % 7;
	std::cout << toneDistance << std::endl;
	if (toneDistance < 0) {
		toneDistance *= -1;
	}

	switch (toneDistance)
	{
	case 1:
	case 6:
		std::cout << "Falshivo zvuchene" << endl;
		break;
	case 4:
		std::cout << "Kuho zvuchene" << endl;
		break;
	case 2:
		std::cout << "Nai-blagopriyatniyat zvuk" << endl;
		break;
	default:
		std::cout << "Normalno zvuchene" << endl;
		break;
	}
}