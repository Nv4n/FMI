//
// Created by Sybatron on 11/2/2022.
//
#include <iostream>

#pragma region QuickSort

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *arr, int left, int right) {
    int low = left - 1;
    int pivot = arr[right];

    for (int i = left; i <= right - 1; ++i) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[low + 1]);
            ++low;
        }
    }
    swap(arr[right], arr[low + 1]);

    return low + 1;
}

void quickSort(int *arr, int left, int right) {
    if (arr == nullptr)
        return;

    for (int i = left; i < right; ++i) {
        int newPivot = partition(arr, left, right);

        quickSort(arr, left, newPivot - 1);
        quickSort(arr, newPivot + 1, right);
    }
}

#pragma endregion


void printArr(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[10] = {0, 5, 7, 9, 10, -10, 5, -3, 6, 0};


    quickSort(arr, 0, 9);
    printArr(arr, 10);
}