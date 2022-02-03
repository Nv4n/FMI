// P00-Comments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

//Напишете програма, която въвежда цяло число N и намира броя на делителите му.
int countDelitel(int n) {
    int counter = 0;
    for (int i = 2; i <= n; i++) {
    //! n/2 не ти трябва да търсиш нататък
        if (n % i == 0) {
            counter++;
        }
    }
    return counter;
    //! return ++counter; ако искаш да допавиш самото число
}
int main()
{
    int n;
    std::cin >> n;

    std::cout << countDelitel(n);
}

//*----------------------------------------------------------------------

#include <iostream>
// Напишете програма, която въвежда цяло положително четирицифрено число N и определя дали в него се съдържа цифрата 2.
bool isContense2(int number) {
    bool isContense = false;
    while (number) {
        if (number % 10 == 2) {
            isContense = true;
            break;
            //! return true; е достатъчно също
        }
        number /= 10;
    }

    return isContense;
    //! return false;
}
int main() {
    int number;
    std::cin >> number;
    std::cout << std::boolalpha << isContense2(number);

}

//*----------------------------------------------------------------------

#include <iostream>
const int MAX_SIZE = 256;
// Дадена е двумерна числова матрица А, с размерност NxN. 
//Напишете програма, която намира сумата на елементите под главния диагонал на масива.

int sumMatrix(int** matrix, int n) {
    int sum = 0;
    for (int rows = 0; rows < n; rows++) {
        //! Почвай направо от rows=1
        for (int columns = 0; columns < n; columns++) {
            //! Правиш го collumns < rows и няма да ти трябва if
            if (rows > 0 && rows > columns) {
                sum += matrix[rows][columns];
            }
        }
    }

    return sum;
}
int main()
{
    int n;
    std::cin >> n;

    int** matrix = new int *[MAX_SIZE];
    //! Защо ползваш MAX_SIZE, а не направо n
    for (int i = 0; i < n; i++) {
        matrix[i] = new int [MAX_SIZE];
        //! направо въвеждай матрицата тук
        // for (int j = 0; j < n; j++) {
        //     std::cin >> matrix[i][j];
        // }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         std::cin >> matrix[i][j];
    //     }
    // }
    std::cout << sumMatrix(matrix, n);
    for (int i = 0; i < size; i++)
    {
        /* code */
        delete[] matrix[i];
    }
    

    delete[] matrix;

}

//*----------------------------------------------------------------------

#include <iostream>
const int MAX_SIZE = 256;
// Напишете програма, която в даден знаков низ заменя всяка главна буква с малка.
int counter(char* niz) {
    int count = 0;
    while (*niz != '\0') {
        count++;
        niz++;
    }
    return count;
}
char* newNiz(char* niz) {
    int element = 0;
    int size = counter(niz);
    char* str = new char[size];
    while (*niz != '\0') {
        if (*niz < 'A' || *niz > 'Z') {
            str[element] = *niz;
            element++;
            niz++;
            continue;
        }
        str[element] = *niz + 32;
        niz++;
        element++;
    }
    str[element] = '\0';
    return str;
}

int main()
{
    char niz[MAX_SIZE];
    std::cin.getline(niz, MAX_SIZE);
    char* nizNew = newNiz(niz);
    while (*nizNew != '\0') {
        std::cout << *nizNew;
        nizNew++;
    }
    delete[] nizNew;
    //! Пак динамичната памет не е изчистена
}

//*----------------------------------------------------------------------

#include <iostream>
#define max_array_size 100000
# include <cmath>

int main(){
    int a;
    int b;
    std :: cin >> a;
    std :: cin >> b;
    std :: cout << std::boolalpha << (b % a == 0) ? true : false;
    //! Не е нужно можеш само 'b % a == 0'

    return 0;
}

//Задача 3
//Въведете две цели числа и проверете дали първото е делител на второто. На конзолата вместо 0 и 1 трябва да изведете True и False.
//
//
//Пример:
//num1 = 5 и num2 = 5 => true
//num1 = 2 и num2 = 9 => false