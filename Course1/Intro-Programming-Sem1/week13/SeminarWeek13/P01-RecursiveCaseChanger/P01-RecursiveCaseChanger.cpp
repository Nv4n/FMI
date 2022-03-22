// P01-RecursiveCaseChanger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void recursiveCaseChanger(char* str, bool* arr) {
	if (*str == '\0')
	{
		return;
	}
	if (*str>='a'||*str<='z' )
	{

	}
	return recursiveCaseChanger(str + 1, arr + 1);
}

int main()
{
	char str[] = "Lorem Ipsum";
	bool arr[] = { false,true,true,false,true,true,true,true,false,false,false,false };
}