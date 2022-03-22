// P03-ForrestTerrain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void changeForestTerrain(char** str, int rowCount, int collumnCount, int years, int row = 0, int collumn = 0);
bool checkNeighbouringAreas(char** str, int rowCount, int collumnCount, int row, int collumn, int count = 0);
int main()
{
	int rowCount;
	int collumnCount;
	std::cin >> collumnCount >> rowCount;
	char** forest = new  char* [rowCount];
	for (int r = 0; r < rowCount; r++)
	{
		forest[r] = new char[collumnCount];
		for (int c = 0; c < collumnCount; c++)
		{
			std::cin >> forest[r][c];
		}
	}

	int years;
	std::cin >> years;
	changeForestTerrain(forest, rowCount, collumnCount, years);

	for (int r = 0; r < rowCount; r++)
	{
		for (int c = 0; c < collumnCount; c++)
		{
			std::cout << forest[r][c] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < rowCount; i++)
	{
		delete[] forest[i];
	}

	delete[] forest;
}

void changeForestTerrain(char** str, int rowCount, int collumnCount, int years, int row, int collumn) {
	if (years < 10) {
		return;
	}

	if (collumn == collumnCount) {
		row++;
		collumn = 0;
	}

	if (row == rowCount)
	{
		row = 0;
		changeForestTerrain(str, rowCount, collumnCount, years - 10, row, collumn);
	}
	else {
		if (str[row][collumn] >= '1' && str[row][collumn] <= '3') {
			str[row][collumn] += 1;
		}
		else if (str[row][collumn] == '4' && checkNeighbouringAreas(str, rowCount, collumnCount, row, collumn)) {
			str[row][collumn] -= 1;
		}

		changeForestTerrain(str, rowCount, collumnCount, years, row, ++collumn);
	}
}

bool checkNeighbouringAreas(char** str, int rowCount, int collumnCount, int row, int collumn, int count) {
	for (int r = 0; r <= row + 1 && r < rowCount; r++)
	{
		for (int c = collumn - 1; c <= collumn + 1 && c < collumnCount; c++)
		{
			if (str[r][c] == '4' && !(r == row && c == collumn))
			{
				count++;
			}
		}
		if (count >= 3) {
			return true;
		}
	}
	return false;
}