// P01-SecondsIntoDaysHoursMinsSecs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int inputSeconds;
	do
	{
		std::cout << "Vavedi broi sekundi: ";
		std::cin >> inputSeconds;
	} while (inputSeconds < 0 || inputSeconds > 10000000); //10^7 10000000 = 10,000,000

	int days;
	int hours;
	int minutes;
	int seconds;

	days = inputSeconds / (60 * 60 * 24);
	inputSeconds = inputSeconds % (60 * 60 * 24);

	hours = inputSeconds / (60 * 60);
	inputSeconds = inputSeconds % (60 * 60);

	minutes = inputSeconds / (60);
	inputSeconds = inputSeconds % 60;

	seconds = inputSeconds;

	std::cout << days << " dni, "
		<< hours << " chasa, "
		<< minutes << " minuti, "
		<< seconds << " secundi"
		<< std::endl;
}