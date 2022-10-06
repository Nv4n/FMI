package com.example.lab01;

import java.util.Scanner;

public class Zad3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter data: ");
        int data = scanner.nextInt();

        //Validating data
        if (data < 1000 || data > 9999)
            throw new IllegalArgumentException("Illegal data (must be 4 digits number): " + data);

        //Encrypting data
        int encryptedData = encryptData(data);

        //Decrypting data
        int decryptedData = decryptData(encryptedData);
        System.out.printf("%d after decrypting is %d%n", encryptedData, decryptedData);
    }

    static int encryptData(int data) {
        int[] modifiedData = new int[4];

        //Encrypting digits
        for (int i = 3; i >= 0; --i) {
            modifiedData[i] += ((data % 10 + 7) % 10);
            data /= 10;
        }

        swapDigits(modifiedData);

        return dataArrayToInteger(modifiedData);
    }

    private static int decryptData(int data) {
        int[] modifiedData = new int[4];

        //Decrypting digits
        for (int i = 3; i >= 0; --i) {
            modifiedData[i] += (data % 10 + 3 /* +10 - 7 */) % 10;
            data /= 10;
        }

        swapDigits(modifiedData);

        return dataArrayToInteger(modifiedData);
    }

    private static int dataArrayToInteger(int[] modifiedData) {
        //Transforming array into integer
        int data = 0;
        //TODO Fix if first digit is 0
        for (int i = 0; i < 4; ++i) {
            data = data * 10 + modifiedData[i];
        }
        return data;
    }

    private static void swapDigits(int[] modifiedData) {
        //Swapping first and third digit
        int temp = modifiedData[0];
        System.out.println(temp);
        modifiedData[0] = modifiedData[2];
        modifiedData[2] = temp;

        //Swapping second and fourth digit
        temp = modifiedData[1];
        modifiedData[1] = modifiedData[3];
        modifiedData[3] = temp;
        System.out.println(temp);
    }
}