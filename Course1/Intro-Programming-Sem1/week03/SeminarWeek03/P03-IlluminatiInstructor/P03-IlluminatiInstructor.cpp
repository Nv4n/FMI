// P03-IlluminatiInstructor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	int firstNumber, secondNumber;
	char symbol;

	std::cout << "Input 2 numbers and a symbol (+, -, *, /, %, ^, =): ";
	std::cin >> firstNumber >> secondNumber >> symbol;
	if (symbol == '=') {
		std::cout << std::boolalpha << (firstNumber == secondNumber) << endl;
	}
	else if (symbol == '+') {
		std::cout << (firstNumber + secondNumber) << endl;
	} 
	else if (symbol == '-') {
		std::cout << (firstNumber - secondNumber) << endl;
	}
	else if(symbol=='*'){
		std::cout << (firstNumber * secondNumber) << endl;
	}
	else if(symbol=='/'){
		std::cout << (firstNumber / secondNumber) << endl;
	}
	else if(symbol == '%'){
		std::cout << (firstNumber % secondNumber) << endl;
	}
	else if(symbol == '^'){
		std::cout << (firstNumber ^ secondNumber) << endl;
	}
	else {
		std::cout << "Invalid operation!";
	}
}