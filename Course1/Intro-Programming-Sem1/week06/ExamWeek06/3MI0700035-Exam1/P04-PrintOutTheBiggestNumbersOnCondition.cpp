// P04-PrintOutTheBiggestNumbersOnCondition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{

	int numbersCount; //n
	int bigNumbersCount; //k
	do
	{
		std::cout << "Vavedi n: ";
		std::cin >> numbersCount;
		std::cout << "Vavedi k: ";
		std::cin >> bigNumbersCount;
	} while (numbersCount < 0 || bigNumbersCount < 0);


	for (int number = numbersCount; number > 0; number--)
	{
		int sumNumberDeviders = 1 + number;
		for (int devider = 2; devider <= number / 2; devider++)
		{
			if (number % devider == 0) {
				sumNumberDeviders = sumNumberDeviders + devider;
			}
		}
		/*std::cout << sumNumberDeviders << std::endl;*/
		if (bigNumbersCount > 0 && sumNumberDeviders % 2 == 1) {
			bigNumbersCount--;
			std::cout << number << " ";
		}
	}
	std::cout << std::endl;
}