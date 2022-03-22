// P08-PoweredNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

int main()
{
    /*Бонус задача

        По зададено число n, да се въведат толкова на брой положителни числа и всяко да се изведе повдигнато на степен, равна на предходното.

        Пример: Вход: 5

        2 4 6 0 61

        Изход :

        2 (4 ^ 2) (6 ^ 4) (0 ^ 6) (61 ^ 0)

        2 16 1296 0 1*/

    int numbersCount;
    std::cin >> numbersCount;
    int number, previousNumber;
    for (int i = 0; i < numbersCount; i++)
    {
        std::cin >> number;
        if (i > 0) {
            std::cout << std::pow(number, previousNumber)<< " ";
        }
        else {
            std::cout << number << " ";
        }
        previousNumber = number;
    }
    std::cout << std::endl;
}