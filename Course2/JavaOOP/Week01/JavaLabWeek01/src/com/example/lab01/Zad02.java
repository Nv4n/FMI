package com.example.lab01;

import java.util.Arrays;
import java.util.Scanner;

public class Zad02 {
    public static void main(String[] args) {
        //Input a 5 digits number
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter 5 digits number: ");
        int number = scanner.nextInt();

        //Number validation
        if (number < 10000 || number > 99999)
            throw new IllegalArgumentException("Illegal number input (must be 5 digits number): " + number);

        int originalNumber = number;

        //Separate number into digits
        int[] digits = new int[5];
        for (int i = 4; i >= 0; --i) {
            digits[i] = number % 10;
            number /= 10;
        }

        String resultString;
        //Validating if the number is palindrome
        if (digits[0] == digits[4] &&
                digits[1] == digits[3]) {
            resultString = String.format("%d is palindrome!%n", originalNumber);
        } else {
            resultString = String.format("%d is NOT palindrome!%n", originalNumber);
        }

        System.out.println(resultString);//Printing the result from the validation
    }
}
