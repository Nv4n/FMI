package lab3.a.Zad4;

import java.util.Scanner;

public class CardTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Input card number: ");
        Card card = new Card(input.nextLong());

        System.out.print("Input card number: ");
        long cardNumber = input.nextLong();

        System.out.printf("Validation status of %d:\t%b", cardNumber, CardValidator.isValid(cardNumber));
    }
}
