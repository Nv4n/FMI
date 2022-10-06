package com.example.lab01;

import java.util.Scanner;

public class Zad01 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean flag = true;

        while (flag) {
            System.out.printf("1. Fahrenheit -> Celsius%n" +
                    "2. Celsius -> Fahrenheit%n" +
                    "3. Exit!%nEnter your choice: ");
            int choice = scanner.nextInt();

            if(choice == 1) {
                System.out.print("Enter degrees in celsius: ");
                double temperature = scanner.nextDouble();
                System.out.println(convertToFahrenheit(temperature));
            } else if (choice == 2) {
                System.out.print("Enter degrees in fahrenheit: ");
                double temperature = scanner.nextDouble();
                System.out.println(convertToCelsius(temperature));
            } else if (choice == 3) {
                flag = false;
            }
        }
    }

    static double convertToCelsius(double temperature) {
        return  9.0 / 5.0 * temperature + 32; //Fahrenheit to Celsius conversion
    }

    static double convertToFahrenheit(double temperature) {
        return 5.0 / 9.0 * (temperature - 32); //Celsius to Fahrenheit conversion
    }
}
