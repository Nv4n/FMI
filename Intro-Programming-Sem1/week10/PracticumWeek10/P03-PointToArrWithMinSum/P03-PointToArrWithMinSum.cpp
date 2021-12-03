// P03-PointToArrWithMinSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int sumArr(int arr[], int size);
double sumArr(double arr[], int size);
void getSmallestSumArr(int* arrA, int sizeA, int* arrB, int sizeB, int*& pointerToSmallestSumArr);
void getSmallestSumArr(double* arrA, int sizeA, double* arrB, int sizeAB, double*& pointerToSmallestSumArr);

void intArrays();
void doubleArrays();

int main()
{
	intArrays();
	//doubleArrays();
}

void intArrays() {
	int sizeA;
	std::cin >> sizeA;
	int* arrA = new int[sizeA];
	for (int i = 0; i < sizeA; i++)
	{
		std::cin >> arrA[i];
	}

	int sizeB;
	std::cin >> sizeB;
	int* arrB = new int[sizeB];
	for (int i = 0; i < sizeB; i++)
	{
		std::cin >> arrB[i];
	}

	int* pointerToSmallestSumArr = nullptr;
	getSmallestSumArr(arrA, sizeA, arrB, sizeB, pointerToSmallestSumArr);
	std::cout << arrA << std::endl << arrB << std::endl << pointerToSmallestSumArr << std::endl;
}
void doubleArrays() {
	int sizeA;
	std::cin >> sizeA;
	double* arrA = new double[sizeA];
	for (int i = 0; i < sizeA; i++)
	{
		std::cin >> arrA[i];
	}

	int sizeB;
	std::cin >> sizeB;
	double* arrB = new double[sizeB];
	for (int i = 0; i < sizeB; i++)
	{
		std::cin >> arrB[i];
	}

	double* pointerToSmallestSumArr = nullptr;
	getSmallestSumArr(arrA, sizeA, arrB, sizeB, pointerToSmallestSumArr);
}

void getSmallestSumArr(int* arrA, int sizeA, int* arrB, int sizeB, int*& pointerToSmallestSumArr) {
	int sumA = sumArr(arrA, sizeA);
	int sumB = sumArr(arrB, sizeB);

	(sumA < sumB) ? pointerToSmallestSumArr = arrA : pointerToSmallestSumArr = arrB;

}
void getSmallestSumArr(double* arrA, int sizeA, double* arrB, int sizeB, double*& pointerToSmallestSumArr) {
	double sumA = sumArr(arrA, sizeA);
	double sumB = sumArr(arrB, sizeB);

	(sumA < sumB) ? pointerToSmallestSumArr = arrA : pointerToSmallestSumArr = arrB;
}

int sumArr(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double sumArr(double arr[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
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
