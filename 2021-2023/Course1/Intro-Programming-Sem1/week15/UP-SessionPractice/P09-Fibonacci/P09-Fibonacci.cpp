// P09-Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int fib(int number, int previous = 0, int current = 1)
{
	if (number == 0)
		return previous;
	if (number == 1)
		return current;
	return fib(number - 1, current, previous + current);
}

int main()
{
	int number;
	std::cin >> number;
	std::cout << fib(number) << std::endl;
	return 0;
}