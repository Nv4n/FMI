// P05-Strlen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int recStrlen(const char* str);
int main()
{
#pragma region LETS GOOO
	int size;
	std::cin >> size;
	char* str = new char[size + 1];
	std::cin.getline(str, 10);
	std::cout << recStrlen(str) << std::endl;
	delete[] str;
#pragma endregion
}
int recStrlen(const char* str) {
#pragma region COMMENT LETS GOOO
	/*int count = 0;
for (; str[count] != '\0'; count++);
return count;*/
#pragma endregion
#pragma region ONE LINE RECURSSION LETS GOOO
	return *str == '\0' ? 0 : 1 + recStrlen(str + 1);
#pragma endregion
}
