// P02-IsThePointInTheShape.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

int main()
{
	int radius = 2;
	double x;// fixed after exam Q-Q
	double y;
	std::cout << "Vavedi X: ";
	std::cin >> x;
	std::cout << "Vavedi Y: ";
	std::cin >> y;

	bool isXInCirleRange = x >= -2 && x <= 2;
	bool isYInCircleRange = y >= 1 && y <= 2;
	bool isPointInColoredCirclePart = isXInCirleRange && isYInCircleRange && sqrt(x * x + y * y) <= radius;

	bool isXOutsideCircleRange = x <= -2 || x >= 2;
	bool isYOutsideCircleRange = y <= 1;
	bool isPointInColoredRectanglePart = isXOutsideCircleRange && isYOutsideCircleRange;

	bool isPointInColoredPart = isPointInColoredCirclePart || isPointInColoredRectanglePart;
	std::cout << "Figurata v ocvetenata chast li e: " << std::boolalpha << isPointInColoredPart << std::endl;
}