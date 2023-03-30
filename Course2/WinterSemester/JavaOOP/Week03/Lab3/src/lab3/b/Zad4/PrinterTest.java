package lab3.b.Zad4;

import java.util.Scanner;

public class PrinterTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Input sequence length: ");
        int[] sequence = new int[input.nextInt()];

        System.out.println("Input sequence: ");
        for (int i = 0; i < sequence.length; i++) {
            System.out.printf("#%d:\t", i + 1);
            sequence[i] = input.nextInt();
        }

        PlatformPrinter printer = new PlatformPrinter(sequence);
        printer.printAllPlatforms();
    }
}
