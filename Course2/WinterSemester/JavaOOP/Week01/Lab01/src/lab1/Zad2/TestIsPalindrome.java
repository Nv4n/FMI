package lab1.Zad2;

import java.util.Scanner;

public class TestIsPalindrome {
    public static void main(String[] args) {
        //Input a 5 digits number
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 5 digits number: ");
        int number = input.nextInt();

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

        String resultString = isPalindrome(digits)
                ? String.format("%d is palindrome!%n", originalNumber)
                : String.format("%d is NOT palindrome!%n", originalNumber);

        System.out.println(resultString);//Printing the result from the validation
    }

    static boolean isPalindrome(int[] digits) {
        //Validating if the number is palindrome
        return digits[0] == digits[4] &&
                digits[1] == digits[3];
    }
}
