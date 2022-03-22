// P01-ToneAnalyzer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;
int main()
{
	int firstTone;
	int	firstOctave;
	do
	{
		std::cout << "Vavedi parvi ton: ";
		std::cin >> firstTone;
		std::cout << "Vavedi negovata oktava: ";
		std::cin >> firstOctave;
	} while ((firstTone < 1 || firstTone > 7) && (firstOctave < 1 || firstOctave > 8));


	int secondTone;
	int secondOctave;
	do
	{
		std::cout << "Vavedi vtori ton: ";
		std::cin >> secondTone;
		std::cout << "Vavedi negovata oktava: ";
		std::cin >> secondOctave;
	} while ((secondTone < 1 || secondTone > 7) && (secondOctave < 1 || secondOctave > 8));

	int toneDistance = ((firstTone + firstOctave * 7) - (secondTone + secondOctave * 7)) % 7;
	if (toneDistance < 0) {
		toneDistance *= -1;
	}

	switch (toneDistance)
	{
	case 1:
	case 6:
		std::cout << "Disonatno zvuchene" << endl;
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