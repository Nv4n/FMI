// P02-BestSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int maxArrayLength(int *arrayLenth, int size);

int stepsToSort(int *arr, int size);

int *mostSortedArr(int **arrayList, int *arrayLength, int size, int &index);

int *worstSortedArr(int **arrayList, int *arrayLength, int size, int &index);

int main() {
    int size;
    do {
        std::cin >> size;
    } while (size < 3);

    int index = 0;
    int **arrayList = new int *[size];
    int *arrayLength = new int[size];

    //Input the LList of the arrays
    for (int arrIndex = 0; arrIndex < size; arrIndex++) {
        int currentArrSize;
        std::cout << "\nInput current array's size: ";
        std::cin >> currentArrSize;

        arrayLength[arrIndex] = currentArrSize;
        arrayList[arrIndex] = new int[currentArrSize];

        for (int elementIndex = 0; elementIndex < currentArrSize; elementIndex++) {
            std::cin >> arrayList[arrIndex][elementIndex];
        }
    }
    //Finding the longest possible length
    int sizeOfArr = maxArrayLength(arrayLength, size);

    //Best sorted array
    int *mostSortedArray = new int[sizeOfArr];
    mostSortedArray = mostSortedArr(arrayList, arrayLength, size, index);
    std::cout << "Best sorted array - { ";
    for (int i = 0; i < arrayLength[index]; i++) {
        std::cout << mostSortedArray[i] << ' ';
    }
    std::cout << "}" << std::endl;

    //Worst Sorted array
    int *worstSortedArray = new int[sizeOfArr];
    worstSortedArray = worstSortedArr(arrayList, arrayLength, size, index);

    std::cout << "Worst sorted array - { ";
    for (int i = 0; i < arrayLength[index]; i++) {
        std::cout << worstSortedArray[i] << ' ';
    }
    std::cout << "}" << std::endl;
    //Clean the dynamic memory
    delete[]arrayLength;
    for (int arrIndex = 0; arrIndex < size; arrIndex++) {
        delete[] arrayList[arrIndex];
    }
    delete[] arrayList;
    delete[] worstSortedArray;
    delete[] mostSortedArray;
    return 0;
}

int maxArrayLength(int *arrayLenth, int size) {
    int maxLength = 2;
    for (int i = 0; i < size; i++) {
        if (maxLength < arrayLenth[i]) {
            maxLength = arrayLenth[i];
        }
    }
    return maxLength;
}

int stepsToSort(int *arr, int size) {
    int *tempArr = new int[size];
    for (int i = 0; i < size; i++) {
        tempArr[i] = arr[i];
    }

    bool flag;
    int counter = 0;
    for (int i = 0; i < size - 1; i++) {
        flag = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (tempArr[j] > tempArr[j + 1]) {
                counter++;
                int tempElement = tempArr[j];
                tempArr[j] = tempArr[j + 1];
                tempArr[j + 1] = tempElement;
                flag = true;
            }
        }
        if (!flag) break;
    }

    return counter;
}

int *mostSortedArr(int **arrayList, int *arrayLength, int size, int &index) {
    int *stepsToSortArr = new int[size];
    for (int i = 0; i < size; i++) {
        stepsToSortArr[i] = stepsToSort(arrayList[i], arrayLength[i]);
    }

    int minStepsToSort = stepsToSortArr[0];
    index = 0;
    for (int i = 1; i < size; i++) {
        if (minStepsToSort > stepsToSortArr[i]) {
            index = i;
            minStepsToSort = stepsToSortArr[i];
            continue;
        }
        if (minStepsToSort == stepsToSortArr[i] && arrayLength[index] < arrayLength[i]) {
            index = i;
            minStepsToSort = stepsToSortArr[i];
        }
    }

    return arrayList[index];
}

int *worstSortedArr(int **arrayList, int *arrayLength, int size, int &index) {
    int *stepsToSortArr = new int[size];
    for (int i = 0; i < size; i++) {
        stepsToSortArr[i] = stepsToSort(arrayList[i], arrayLength[i]);
    }

    int maxStepsToSort = stepsToSortArr[0];
    index = 0;
    for (int i = 1; i < size; i++) {
        if (maxStepsToSort < stepsToSortArr[i]) {
            index = i;
            maxStepsToSort = stepsToSortArr[i];
            continue;
        }
        if (maxStepsToSort == stepsToSortArr[i] && arrayLength[index] < arrayLength[i]) {
            index = i;
            maxStepsToSort = stepsToSortArr[i];
        }
    }

    return arrayList[index];
}