package Zad1.b;

import java.util.Scanner;

public class PhoneCoderTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        PhoneCoder coder = new PhoneCoder(3);
        System.out.print("Enter start number: ");
        String startNumber = input.nextLine();
        String encodedNumber = coder.encode(startNumber);
        System.out.printf("Encoded number: %s%n", encodedNumber);
        System.out.printf("Decoded number: %s%n", coder.decode(encodedNumber));
    }
}
