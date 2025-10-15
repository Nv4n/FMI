// P01-SumArrayElements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double returnArraySum(double* numbersArr, int arrLenght) {
	double sum = 0;
	for (int i = 0; i < arrLenght; i++)
	{
		sum += numbersArr[i];
	}
	return sum;
}

int main()
{
	int arrLength;
	std::cin >> arrLength;
	double* numbersArray = new double[arrLength];
	for (int i = 0; i < arrLength; i++)
	{
		std::cin >> numbersArray[i];
	}
	double result = returnArraySum(numbersArray, arrLength);
	std::cout << result << std::endl;
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
