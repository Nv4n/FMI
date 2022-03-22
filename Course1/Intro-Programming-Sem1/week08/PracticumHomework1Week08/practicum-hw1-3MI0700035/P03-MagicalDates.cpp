// P03-MagicalDates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int daysInMonth(int month, int year);
int getSum(int year, int month, int day);

int main()
{
	int startYear;
	int endYear;
	int magicalSum;
	do
	{
		std::cout << "Enter starting year: ";
		std::cin >> startYear;
		std::cout << "Enter end year: ";
		std::cin >> endYear;
		std::cout << "Enter the magical sum: ";
		std::cin >> magicalSum;
	} while (startYear < 0 || endYear<0 || startYear>endYear
		|| magicalSum < 0);
	for (int year = startYear; year <= endYear; year++)
	{
		for (int month = 1; month <= 12; month++)
		{
			int daysCount = daysInMonth(month, year);
			for (int day = 1; day <= daysCount; day++)
			{
				int sum = getSum(year, month, day);
				if (sum == magicalSum) {
					printf("%02d-%02d-%04d\n", day, month, year);
				}
			}
		}
	}
}

int getSum(int year, int month, int day) {
	int numberInArray[8] = {
		day / 10,day % 10, //day in digits
		month / 10,month % 10, //month in digits
		year / 1000, year % 1000 / 100,year % 100 / 10,year % 10 //year in digits
	};

	int totalSum = 0;
	for (int currentNumberIndex = 0; currentNumberIndex < 8; currentNumberIndex++)
	{
		if (numberInArray[currentNumberIndex] != 0)
		{
			int currentSum = 0;
			for (int numberIndex = currentNumberIndex + 1; numberIndex < 8; numberIndex++)
			{
				currentSum += numberInArray[numberIndex];
			}
			totalSum += numberInArray[currentNumberIndex] * currentSum;
		}
	}

	return totalSum;
}

int daysInMonth(int month, int year) {
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			return 29;
		}
		else {
			return 28;
		}
	}
}