// P06-ReversedNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	/*Задача 6

		По въведено число изкарайте неговоротo обратно.*/
	int number;
	std::cout << "Input a number: ";
	std::cin >> number;

	//for (; number != 0; number /= 10) {
	//	std::cout << number % 10;
	//}
	//std::cout << std::endl;

	int product = 0;
	while (number != 0)
	{
		product = product * 10 + number % 10;
		number /= 10;
	}
	std::cout << product << std::endl;
}
