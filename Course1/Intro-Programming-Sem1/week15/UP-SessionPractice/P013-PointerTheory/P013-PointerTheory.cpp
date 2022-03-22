// P013-PointerTheory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void modify(int* n) {
	n += 5;
}
void modify(int*& n) {
	n += 5;
}
void modify(int** n) {
	n += 5;
}

int main()
{
	int* n;

	//modify(n);
	std::cout << n << std::endl;
}

//int main() {
//	int good = 1, bad = 0;
//	if (bad = good)std::cout << ":(";
//	if (good != bad)std::cout << ":)";
//	std::cout << (good - true) * 84753 * (bad || 36589) + !(!good && true) << std::endl;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
