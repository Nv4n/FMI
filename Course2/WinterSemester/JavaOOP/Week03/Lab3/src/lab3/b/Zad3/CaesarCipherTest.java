package lab3.b.Zad3;

import java.util.Scanner;

public class CaesarCipherTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Input data: ");
        String data = new String(input.nextLine());
        String encryptedData = CaesarCipher.encrypt(data);
        String decryptedData = CaesarCipher.decrypt(encryptedData);
        System.out.printf("%1$s -> %2$s -> %3$s",
                data,
                encryptedData,
                decryptedData);
    }
}
