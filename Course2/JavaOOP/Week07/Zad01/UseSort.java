package Zad01;

import org.jetbrains.annotations.NotNull;

import java.util.Arrays;

public class UseSort {
    public static void main(String[] args) {
        int[] arr = new int[]{4, 6, 9, 0, 10, -1, 2, 11};
        MySort sort = new MySort(SortOrder.getUpward());
        sort.sort(arr);
        System.out.printf("Upward: %s%n", Arrays.toString(arr));
        // TODO: 11/17/2022
        //  Anonymous class implementation

        sort.setCallback(SortOrder.getDownward());
        sort.sort(arr);
        System.out.printf("Downward: %s%n", Arrays.toString(arr));

    }
}
