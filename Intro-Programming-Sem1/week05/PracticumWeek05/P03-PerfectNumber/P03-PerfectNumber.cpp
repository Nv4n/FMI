// P03-PerfectNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int number;
	std::cout << "Input a number: ";
	std::cin >> number;
	int sum = 1;

	for (int devider = 2; devider <= number / 2; devider++)
	{
		if (number % devider == 0) {
			sum += devider;
		}
	}

	if (sum == number) {
		std::cout << "Perfect!"<<std::endl;
	}
	else {
		std::cout << "Not perfect!" << std::endl;
	}
}
//Задача 3
//Да се провери дали едно цяло число е съвършено.Едно число е съвършено, когато е равно на сбора от делителите си(без самото число). 6 е съвършено - делители 1, 2 и 3.
//
//
//Примерен изход при вход 6: Perfect!
//Примерен изход при вход 5 Not perfect!
//Примерен изход при вход 28 : Perfect!