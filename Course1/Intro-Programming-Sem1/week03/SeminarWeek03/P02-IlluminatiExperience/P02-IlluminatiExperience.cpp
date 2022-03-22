// P02-IlluminatiExperience.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::endl;

int main()
{
	int age;
	std::cout << "Input your age: ";
	std::cin >> age;

	if (age >= 65) {
		std::cout << "You are the leader - 5000 points";
	}
	else if (age < 0) {
		std::cout << "You are banished from the illuminati"<<endl;
	}
	else {
		int points = 0;
		//We add the points for each year
		points += age * 3;

		//If age>18 each year after 18th is 5 points so add additional 2 points for years afer 18th
		if (age > 18) {
			points += (age - 18) * 2;
		}

		std::cout << "At age of " << age << " you have " << points << " experience points" << endl;
	}
}