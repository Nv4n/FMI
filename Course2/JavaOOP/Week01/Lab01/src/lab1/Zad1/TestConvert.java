package lab1.Zad1;

import java.util.Scanner;

public class TestConvert {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean flag = true;

        while (flag) {
            System.out.printf("1. Celsius -> Fahrenheit%n" +
                    "2. Fahrenheit -> Celsius%n" +
                    "3. Exit!%nEnter your choice: ");
            int choice = input.nextInt();

            if (choice == 1) {
                System.out.print("Enter degrees in celsius: ");
                Celsius celsius = new Celsius(input.nextDouble());
                System.out.printf("%.2f%n", celsius.convertToFahrenheit());

            } else if (choice == 2) {
                System.out.print("Enter degrees in fahrenheit: ");
                Fahrenheit fahrenheit = new Fahrenheit(input.nextDouble());
                System.out.printf("%.2f%n", fahrenheit.convertToCelsius());
            } else if (choice == 3) {
                flag = false;
            } else {
                System.out.printf("Choice doesn't exist: %d%n", choice);
            }
        }
    }
}
