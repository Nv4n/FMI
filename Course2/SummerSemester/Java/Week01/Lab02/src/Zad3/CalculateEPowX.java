package Zad3;

import java.util.Scanner;

public class CalculateEPowX {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter x: ");
        int x = input.nextInt();
        int currentXPowered = x;
        int permutationNumber = 1;
        double currentEPowX = 1;
        double prevEPowX = 0;
        int iterationCount = 1;

        while (Math.abs(prevEPowX - currentEPowX) >= 0.001) {
            System.out.printf("Iteration #%d: %f%n", iterationCount++, currentEPowX);
            prevEPowX = currentEPowX;
            currentEPowX = currentEPowX + (1.0 * currentXPowered / permutationNumber);
            currentXPowered *= x;
            permutationNumber *= (permutationNumber + 1);
        }
    }
}
