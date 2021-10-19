// P01-Illuminati.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	double side1, side2, side3;
	std::cin >> side1 >> side2 >> side3;

	if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
	{
		std::cout << "Triangle doesn't exist" << std::endl;
		return;
	}

	if (side1 >= side2 && side1 >= side3)
	{
		double temp = side1;
		side1 = side3;
		side3 = temp;
	}
	else if (side2 >= side1 && side2 >= side3)
	{
		double temp = side2;
		side2 = side3;
		side3 = temp;
	}

	double conditionValue1 = side1 * side1 + side2 * side2;
	double conditionValue2 = side3 * side3;

	if (conditionValue1 == conditionValue2)
	{
		std::cout << "Right Triangle Family" << std::endl;
	}
	else if(conditionValue1 > conditionValue2) 
	{
		std::cout << "Sharp Triangle Family" << std::endl;
	}
	else
	{
		std::cout << "Not Sharp Triangle Family" << std::endl;
	}
}
