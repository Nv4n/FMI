package problem1;

import java.util.Scanner;

public class Hamming {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num1 = input.nextInt();
        int num2 = input.nextInt();

        if (num1 < 0 || num1 > 255) {
            System.out.println("First number is not 8bits");
            return;
        }
        if (num2 < 0 || num2 > 255) {
            System.out.println("Second number is not 8bits");
            return;
        }
        char[] bin1 = getBinary(num1);
        char[] bin2 = getBinary(num2);

        int hamming = 0;
        for (int i = 0; i < bin1.length; i++)
            if (bin1[i] != bin2[i]) hamming++;

        System.out.printf("num1: %s%nnum2: %s%nhamming: %d",
                new String(bin1),
                new String(bin2),
                hamming);
    }

    private static char[] getBinary(int num) {
        char[] result = new char[8];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = num % 2 == 1 ? '1' : '0';
            num /= 2;
        }

        return result;
    }

}
