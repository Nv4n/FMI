// P02-IsThePointInTheShapeV02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int radius = 2;
	double x;
	double y;
	std::cout << "Vavedi X: ";
	std::cin >> x;
	std::cout << "Vavedi Y: ";
	std::cin >> y;

	bool isXInCirleRange = x >= -2 && x <= 1;
	bool isYInCircleRange = y >= -2 && y <= 2;
	bool isPointInColoredCirclePart = isXInCirleRange && isYInCircleRange && sqrt(x * x + y * y) <= radius;

	bool isXOutsideCircleRange = x >= 1;
	bool isPointInWhiteCirlceArea = x > 1 && isYInCircleRange && sqrt(x * x + y * y) <= radius;
	bool isPointInColoredRectanglePart = isXOutsideCircleRange && !isPointInWhiteCirlceArea;

	bool isPointInColoredPart = isPointInColoredCirclePart || isPointInColoredRectanglePart;
	std::cout << "Figurata v ocvetenata chast li e: " << std::boolalpha << isPointInColoredPart << std::endl;
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
