package lab4.plus.Zad6;

import java.util.Scanner;

public class MultiplyMatrixTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
    }

    public static double[][] multiplyMatrix(double[][] a, double[][] b) {
        double[][] result = new double[a.length][b[0].length];
        for (int ci = 0; ci < b[0].length; ci++)
            for (int ri = 0; ri < a.length; ri++)
                result[ci][ci] += a[ci][ri] * b[ri][ci];

        return result;
    }
}
