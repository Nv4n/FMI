//
// Created by Sybatron on 11/3/2022.
//
#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int sortPartition(int *&arr, int start, int end) {
    int low = start - 1;
    int pivot = arr[end];

    for (int i = start; i <= end - 1; ++i) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[++low]);
        }
    }

    swap(arr[++low], arr[end]);
    return low;
}

void quickSort(int *&arr, int start, int end) {
    for (int i = start; i < end; ++i) {
        int newPivot = sortPartition(arr, start, end);
        quickSort(arr, start, newPivot - 1);
        quickSort(arr, newPivot + 1, end);
    }
}

void printArr(int *&arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int *arr = new int[10]{0, 2, 10, -5, 13, 5, 0, 7, 3, 2};
    quickSort(arr, 0, 9);
    printArr(arr, 10);
    delete[] arr;
}