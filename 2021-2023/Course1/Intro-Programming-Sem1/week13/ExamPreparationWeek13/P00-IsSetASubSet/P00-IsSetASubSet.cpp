// P00-IsSetASubSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isSet(size_t arr[], size_t length) {
	for (int i = 0; i < length; i++)
	{
		for (int j = 1; j < length; j++)
		{
			if (arr[i] == arr[j])
			{
				return false;
			}
		}
	}

	return true;
}
bool doesConsist(size_t arr[], size_t length, size_t elementToCheck) {
	if (length == 0)
	{
		return false;
	}

}

bool isSubSet(size_t arr1[], size_t arr2[], size_t length1, size_t length2) {
	if (length1 == 0)
	{
		return true;
	}
	if (!doesConsist(arr2, length2, arr1[0])) {
		return false;
	}
}

int main()
{
	size_t arr1[5] = { 2,1,5,4,6 };
	size_t arr2[9] = { 1,2,3,4,5,6,7,18,11 };
	if (isSet(arr1, 5) && isSet(arr2, 9)) {
		std::cout << std::boolalpha << isSubSet(arr1, arr2, 5, 9) << std::endl;
	}
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
