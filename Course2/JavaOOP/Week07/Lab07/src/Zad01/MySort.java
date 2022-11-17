package Zad01;

import org.jetbrains.annotations.NotNull;

public class MySort {
    private Sortable callback;

    public MySort(Sortable callback) {
        setCallback(callback);
    }

    public void setCallback(@NotNull Sortable callback) {
        this.callback = callback;
    }

    public void sort(int[] arr) {
        for (int i = 0; i < arr.length; i++)
            for (int j = 0; j < arr.length - 1; j++)
                if (callback.greaterThan(arr[j], arr[j + 1])) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
    }
}
