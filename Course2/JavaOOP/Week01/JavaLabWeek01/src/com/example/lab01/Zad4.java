package com.example.lab01;

import java.util.Scanner;

public class Zad4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter genetic information: ");
        int geneticInformation = scanner.nextInt();

        //Data validation
        if (geneticInformation < 1000 || geneticInformation > 9999)
            throw new IllegalArgumentException("Illegal geneticInformation (must be 4 digits): ");

        int[] nucBases = new int[4];
        int[] stepsOfFour = {1, 4, 16, 64}; //Steps of 4: 4^0, 4^1, 4^2 and 4^3
        for (int i = 3; i >= 0; --i) {
            int stepsDivisions = geneticInformation / stepsOfFour[i];
            int nucBaseNumber = stepsDivisions < 3 ? stepsDivisions : 3;
            nucBases[i] = nucBaseNumber;

            geneticInformation -= (stepsOfFour[i] * nucBaseNumber);
        }

        for (int i = 0; i < 4; i++) {
            System.out.printf("%d ", nucBases[i]);
        }
        System.out.println();
    }
}
