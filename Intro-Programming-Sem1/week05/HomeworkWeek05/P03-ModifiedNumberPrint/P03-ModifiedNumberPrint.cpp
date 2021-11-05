// P03-ModifiedNumberPrint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int number;
    std::cin >> number;
    int firstDigit = number / 100;
    int secondDigit = number % 100 / 10;
    int thirdDigit = number % 10;

    int rowCount = firstDigit + secondDigit;
    int collumnCount = firstDigit + thirdDigit;
    for (int row = 0; row < rowCount; row++)
    {
        for (int collumn = 0; collumn < collumnCount; collumn++)
        {
            if (number % 5 == 0) {
                number -= firstDigit;
            }
            else if (number % 3 == 0) {
                number -= secondDigit;
            }
            else {
                number += thirdDigit;
            }

            std::cout << number << " ";
        }
        std::cout << std::endl;
    }
}
/*1)Ако числото се дели на 5, извадете от него първата му цифра.
//2)Ако числото се дели на 3, извадете от него втората му цифра.
//3)Ако нито едно от горните условия не е вярно, прибавете към него третата му
цифра.*/