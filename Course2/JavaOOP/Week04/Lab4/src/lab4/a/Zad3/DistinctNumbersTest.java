package lab4.a.Zad3;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DistinctNumbersTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Integer> sequence = new ArrayList<Integer>();
        int num;
        do {
            num = input.nextInt();
            sequence.add(num);
        } while (num != 0);
        sequence.remove(sequence.size() - 1);
        System.out.println(sequence);
        printAllDistinctNumbers(sequence);
    }

    private static void printAllDistinctNumbers(ArrayList<Integer> sequence) {
        ArrayList<Integer> distinct = new ArrayList<>(sequence);
        getAllDistinctNumbers(distinct);
        System.out.printf("All distinct numbers: %s", distinct);
    }

    private static void getAllDistinctNumbers(ArrayList<Integer> sequence) {
        for (int i = 0; i < sequence.size(); i++)
            if (sequence.lastIndexOf(sequence.get(i)) != i) {
                sequence.removeAll(List.of(sequence.get(i)));
                i--;
            }
    }
}
