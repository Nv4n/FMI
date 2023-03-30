package Zad5.a;

import java.util.Scanner;

public class CalculateE {
    public static void main(String[] args) {
        double currentEValue = 1;
        int permutationIndex = 2;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the precision: ");
        int precision = input.nextInt();
        int floatingPointDigitsCount = 0;

        while (floatingPointDigitsCount < precision) {
            currentEValue = currentEValue + (1.0 / (permutationIndex * (permutationIndex + 1)));
            permutationIndex++;
            floatingPointDigitsCount = Double.toString(currentEValue).split("\\.")[1].length();
        }
        System.out.printf("Result with precision %d is: %." + precision + "f",
                precision,
                currentEValue);
    }
}
