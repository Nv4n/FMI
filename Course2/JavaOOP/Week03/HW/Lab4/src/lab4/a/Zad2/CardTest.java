package lab4.a.Zad2;

import java.util.Scanner;

public class CardTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a credit card number as a long integer: ");
        Card card = new Card(input.nextLong());

        System.out.printf("Validation status of %d:\t%b",
                card.getCardNumber(),
                CardValidator.isValid(card.getCardNumber()));
    }
}
