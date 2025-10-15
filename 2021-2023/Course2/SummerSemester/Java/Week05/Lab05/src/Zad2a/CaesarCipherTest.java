package Zad2a;

import java.util.Scanner;

public class CaesarCipherTest {
    public static void main(String[] args) {
        getMenu();


    }

    private static void getMenu() {
        System.out.print("""
                Въведи 1 за кодиране
                Въведи 2 за декодиране
                Въведи 3 за иход:\t\
                """);
        getChoice();
    }

    private static void getChoice() {
        Scanner input = new Scanner(System.in);
        int choice = input.nextInt();
        switch (choice) {
            case 1 -> {
                System.out.print("Въведи текст:\t");
                String data = input.next();
                if (input.hasNextLine()) {
                    System.out.printf("Кодирано съобщение:\t%s%n%n",
                            CaesarCipher.encrypt(data));
                    getMenu();
                }
            }
            case 2 -> {
                System.out.print("Въведи текст:\t");
                String data = input.next();
                if (input.hasNextLine()) {
                    System.out.printf("Декодирано съобщение:\t%s%n%n",
                            CaesarCipher.decrypt(data));
                    getMenu();
                }
            }
            case 3 -> {
            }

            default -> {
                System.out.print("Невалидна опция опитай пак:\t");
                getChoice();
            }
        }

    }
}
