// P14-MatrixCalculationsInDiogonals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
bool isTheSpecialEquationTrue(int** matrix, int size);
int main()
{
	int size;
	do
	{
		std::cin >> size;
	} while (size < 3);
	int** matrix = new int* [size];
	for (int row = 0; row < size; row++) {
		matrix[row] = new int[size];
		for (int col = 0; col < size; col++) {
			std::cin >> matrix[row][col];
		}
	}

	std::cout << std::boolalpha << isTheSpecialEquationTrue(matrix, size) << std::endl;

	for (int row = 0; row < size; row++) {
		delete[] matrix[row];
	}
	delete[] matrix;
}
bool isTheSpecialEquationTrue(int** matrix, int size) {
	int mainDiagonals[4] = { 1,1,1,1 };
	/*
	0 1
	2 3
	*/
	int secondDiagonals[4] = { 1,1,1,1 };
	/*
	1 0
	3 2
	*/

	for (int row = 0, colMain = 0, col2nd = size - 1, index = 0;
		row == size && colMain == size && col2nd == -1;
		row++, colMain++, col2nd--) {

		if (row == size) {
			row = size / 2;
			index++;
			continue;
		}
		if (colMain == size) {
			colMain = -1;
			col2nd = size;
			index++;
			continue;
		}
		if (colMain == size / 2) {
			row = -1;
			index++;
			continue;
		}

		mainDiagonals[index] *= matrix[row][colMain];
		secondDiagonals[index] *= matrix[row][col2nd];
	}

	bool isConditionTrue = (mainDiagonals[1] - secondDiagonals[0] == mainDiagonals[2] - secondDiagonals[3]) &&
		(mainDiagonals[0] - secondDiagonals[1] == mainDiagonals[3] - secondDiagonals[2]);

	if (isConditionTrue)
	{
		return true;
	}
	return false;
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
