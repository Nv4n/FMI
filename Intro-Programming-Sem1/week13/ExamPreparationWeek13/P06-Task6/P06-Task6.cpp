// P06-Task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void letterSwap(char* str, int arr[]) {
	if (*str == '\0')
	{
		return;
	}

	arr[0] %= 26;
	if (*str >= 'A' && *str <= 'Z')
	{
		*str += arr[0];
		if (*str > 'Z')
		{
			*str -= 26;
		}
	}
	else if (*str >= 'a' && *str <= 'z') {
		*str += arr[0];
		if (*str > 'z')
		{
			*str -= 26;
		}
	}
	return letterSwap(str + 1, arr + 1);
}
int main()
{
	char str[] = "LoremIpsum";
	std::cout << str << std::endl;
	int arr[] = { 1, 0, 2, 5, 6, 2, 11, 9, 3, 3 };
	letterSwap(str, arr);
	std::cout << str << std::endl;
}

//Задача 6
//Напишете рекурсивна функция, която приема символен низ, състоящ се само от малки и главни английски букви, и масив от цели числа със същата дължина.Функцията трябва да замени буквата на i - та позиция в символния низ с буквата, която е след нея в английската азбука на разстояние, определено от i - тия елемент в масива от цели числа.Следващите букви на последните са първите в азбуката(т.е.ако Z трябва да се смени със следващата буква, трябва да поставим A).Пример:
//
//Пример:
//Вход:
//"LoremIpsum"
//[1, 0, 2, 5, 6, 2, 11, 9, 3, 3]
//Изход :
//    "MotjsKabxp"
