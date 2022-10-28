package lab4.a.Zad5;

import java.util.Scanner;

public class BarCodeTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter ZIP-code: ");
        int zip = input.nextInt();

        String result = BarCode.decode(zip);
        System.out.println(result);
    }
}
