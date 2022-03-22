// P00-WillTraichoEat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	/*Ако ще прави студентска салата, ще му трябват 1 домат, 2 чушки, 4 моркова, 3 маслини, 3 картофа и 150мл овкусители.

		Ако ще прави студентска супа, ще му трябват 2 домата, 3 чушки, 5 моркова, 6 маслини, 10 картофа и 200мл овкусители.

		Ако ще прави студентски гювеч(и за приятели), ще му трябват 5 домата, 6 чушки, 12 моркова, 7 маслини, 12 картофа и 300мл овкусители.*/
		/*По даден брой домати, брой чушки, брой моркови, брой маслини, брой картофи, мл.овкусители и дали ще дойде един приятел с него за помощ, напишете булев израз, който определя дали Трайчо има продукти да си направи ястия и да се нахрани заслужено след Алгебрата и Геометрията.*/

	int tomatoesCount;
	std::cin >> tomatoesCount;
	int peppersCount;
	std::cin >> peppersCount;
	int carrotsCount;
	std::cin >> carrotsCount;
	int olivesCount;
	std::cin >> olivesCount;
	int potatoesCount;
	std::cin >> potatoesCount;
	int seasoningMl;
	std::cin >> seasoningMl;
	bool isFriendComing;
	std::cout << "Is a friend coming to help us: ";
	std::cin >> isFriendComing;

	bool isTraichoEating = (tomatoesCount == 1 || tomatoesCount > 1 && isFriendComing) && peppersCount >= 2 &&
		carrotsCount >= 4 && olivesCount >= 3 &&
		potatoesCount >= 3 && seasoningMl >= 150;

	std::cout << "Will Traicho eat: " << std::boolalpha << isTraichoEating << std::endl;
}