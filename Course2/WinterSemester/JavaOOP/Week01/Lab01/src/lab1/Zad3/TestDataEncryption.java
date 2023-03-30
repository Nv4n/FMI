package lab1.Zad3;

import java.util.Scanner;

public class TestDataEncryption {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter data: ");
        Data data = new Data(input.nextInt());

        data.encryptData();
        System.out.printf("Encrypted data: %04d%n", data.getData());
        data.decryptData();
        System.out.printf("Decrypted data: %04d%n", data.getData());
        System.out.printf("Original data: %04d%n", data.getOriginalData());
    }
}