// P03-FindNumberInMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int rowCount;
	int collumnCount;

	std::cin >> rowCount >> collumnCount;

	int numberToFind;
	std::cin >> numberToFind;
	int** matrix = new int* [rowCount];
	for (int row = 0; row < rowCount; row++)
	{
		matrix[row] = new int[collumnCount];
		for (int collumn = 0; collumn < collumnCount; collumn++)
		{
			std::cin >> matrix[row][collumn];
		}
	}

	bool isTheNumberFound = false;
	for (int row = 0; row < rowCount; row++)
	{
		for (int collumn = 0; collumn < collumnCount; collumn++)
		{
			if (numberToFind == matrix[row][collumn])
			{
				std::cout << numberToFind << " has been found on Row: " << row << " Collumn: " << collumn << std::endl;
				matrix[row][collumn] *= 10;

				isTheNumberFound = true;
			}
		}
	}

	if (isTheNumberFound) {
		std::cout << "We couln't find the number sorry 😢" << std::endl;
	}
}

	

	//3 задача
	//Да се въвежда цяло число х, да се провери дали х е елемент на матрицата, и ако е - да се изведе позицията на елемнта в матрицата и елемента да се умножи по 10, а ако не е елемент на матрицата да се изведе подходящо съобщение.