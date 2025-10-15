// WECANDOIT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int count = 0;
	for (int a = 1; a <= 4; a++)//1 4
	{
		for (int b = a + 1; b <= 5; b++)//2 5 
		{
			for (int c = b + 1; c <= 6; c++)//3 6
			{
				for (int d = c + 1; d <= 7; d++)//4 7
				{
					for (int e = d + 1; e <= 8; e++)//5 8
					{
						for (int f = e + 1; f <= 9; f++)//6 9
						{
							count++;
						}
					}
				}
			}
		}
	}

	std::cout << count << std::endl;
}
//1 2 3 4 5 6 7 8 9



//2 3 5 100