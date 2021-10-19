#include <iostream>

int main()
{
	int problemChoice;
	std::cout << "Enter which problem you want to be run: ";
	std::cin >> problemChoice;

	switch (problemChoice)
	{
	case 1: {
		//Problem 1             
		std::cout << "Problem 1" << std::endl;
		std::cout << "Algebrata ne proshtava" << std::endl << std::endl;
		break;
	}
	case 2: {
		//Problem 2
		std::cout << "Problem 2" << std::endl;
		double side1, side2, side3;
		std::cout << "Enter 3 sides of a triangle: ";
		std::cin >> side1 >> side2 >> side3;

		std::cout << "This triangle exist?: " << std::boolalpha
			<< (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2)
			<< std::endl;
		break;
	}
	case 3: {
		//Problem 3
		std::cout << "Problem 3" << std::endl;
		int num1, num2;
		std::cout << "Enter 2 real numbers: ";
		std::cin >> num1 >> num2;

		std::cout << "Sum: " << num1 + num2 << std::endl
			<< "Difference: " << num1 - num2 << std::endl
			<< "Product: " << num1 * num2
			<< std::endl;
		break;
	}
	case 4: {
		//Problem 4
		std::cout << "Problem 4" << std::endl;
		int number;
		std::cout << "Enter a 3 digits number: ";
		std::cin >> number;
		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			int digit = number % 10;
			sum += digit;
			std::cout << "Digit " << i + 1 << ": " << digit << std::endl;
			number /= 10;
		}
		std::cout << "Sum: " << sum << std::endl;
		break;
	}
	case 5: {
		//Problem 5
		std::cout << "Problem 5" << std::endl;
		std::cout << "Enter coordinates x and y: ";
		int pointX, pointY;
		std::cin >> pointX >> pointY;
		std::cout << "Enter circle's center coordinates: ";
		int centerX, centerY;
		std::cin >> centerX >> centerY;
		std::cout << "Enter the radius: ";
		double radius;
		std::cin >> radius;
		double distancePointCenter = std::sqrt(
			std::pow(std::abs(pointX - centerX), 2)
			+ std::pow(std::abs(pointY - centerY), 2)
		);

		std::cout << "Point lies on the circle?: " << std::boolalpha
			<< (distancePointCenter == radius) << std::endl;
	}
	default: {
		std::cout << "Problem number not valid!" << std::endl;
	}
	}
}

//Задача 1
//Да се изведе на конзолата "Algebrata ne proshtava"
//
//Задача 2
//Да се въведат три променливи - реални числа и да се провери дали съществува триъгълник със страни тези числа
//
//Задача 3
//Напишете програма, която по въведени 2 числа извежда на конзолата техния сбор, разлика и произведение на отделни редове.
//
//Пример:
//
//Вход: 2 5 Изход : Sum : 7 Difference : -3 Product : 10
//
//Задача 4
//Да се въведе от клавиатурата положително трицифрено цяло число.Да се намерят и отпечатат цифрите му и да се намери сумата им.
//
//Задача 5
//Да се провери дали точка със зададени координати(x, y) лежи на окръжност с център точка(c1, c2) и радиус r.