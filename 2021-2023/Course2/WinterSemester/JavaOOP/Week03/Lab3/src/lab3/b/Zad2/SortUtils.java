package lab3.b.Zad2;

import java.util.Scanner;

public class SortUtils {
    private static final Scanner input = new Scanner(System.in);

    public static void init(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.printf("[%d]: ", i);
            a[i] = input.nextInt();
        }
    }

    public static void print(int[] a) {
        System.out.print("[");
        for (int i = 0; i < a.length - 1; i++) {
            System.out.printf(" %d,", a[i]);
        }
        System.out.printf(" %d]%n", a[a.length - 1]);
    }

    public static void sortBbl(int[] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = i; j < a.length - 1; j++) {
                if (a[j] <= a[j + 1])
                    continue;

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    public static int[] mergeSort(int[] a, int[] b) {
        int[] merged = new int[a.length + b.length];
        for (int i = 0, ai = 0, bi = 0; i < merged.length; i++) {
            if (ai < a.length && a[ai] < b[bi]) {
                merged[i] = a[ai];
                ai++;
            } else {
                merged[i] = b[bi];
                bi++;
            }
        }
        return merged;
    }
}
