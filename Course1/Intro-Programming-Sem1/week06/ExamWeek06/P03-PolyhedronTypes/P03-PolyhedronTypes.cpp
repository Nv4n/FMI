// P03-PolyhedronTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int startingNumber;
	int endingNumber;
	do
	{
		std::cin >> startingNumber;
		std::cin >> endingNumber;
	} while (startingNumber < 0 && endingNumber < 0);

	for (int number = startingNumber; number <= endingNumber; number++)
	{
		int tempNumber = number;
		while (tempNumber > 0)
		{
			if (tempNumber >= 20) {
				tempNumber = tempNumber - 20 * (tempNumber / 20);
				std::cout << "Water";
			}
			else if (tempNumber >= 12) {
				tempNumber = tempNumber - 12 * (tempNumber / 12);
				std::cout << "Universe";
			}
			else if (tempNumber >= 8) {
				tempNumber = tempNumber - 8 * (tempNumber / 8);
				std::cout << "Air";
			}
			else if (tempNumber >= 6) {
				tempNumber = tempNumber - 6 * (tempNumber / 6);
				std::cout << "Earth";
			}
			else if (tempNumber >= 4) {
				tempNumber = tempNumber - 4 * (tempNumber / 4);
				std::cout << "Fire";
			}
			else {
				tempNumber = 0;
				std::cout << "Plasma";
			}
		}
		std::cout << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
