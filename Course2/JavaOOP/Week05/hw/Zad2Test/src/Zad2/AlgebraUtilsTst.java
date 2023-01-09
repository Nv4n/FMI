package Zad2;

import java.util.Scanner;

public class AlgebraUtilsTst {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double[][] matrixA = initMatrix("Enter matrix 1:\t", input);

        double[][] matrixB = initMatrix("Enter matrix 2:\t", input);

        double[][] resMatrix = AlgebraUtils.multiplyMatrix(matrixA, matrixB);
        displayMultiplication(matrixA, matrixB, resMatrix);
    }

    private static double[][] initMatrix(String s, Scanner input) {
        System.out.print(s);
        double[][] matrix = new double[3][3];
        for (int ri = 0; ri < 3; ri++)
            for (int ci = 0; ci < 3; ci++)
                matrix[ri][ci] = input.nextDouble();
        return matrix;
    }

    private static void displayMultiplication(double[][] a, double[][] b, double[][] res) {
        System.out.println("The multiplication of the matrices is");
        int centerRowI = Math.min(Math.min(a.length, b.length), res.length) / 2;
        int lstRowI = Math.max(Math.max(a.length, b.length), res.length);

        for (int ri = 0; ri < lstRowI; ri++) {
            String mARow = null;
            String mBRow = null;
            String mResRow = null;
            if (ri < a.length)
                mARow = matrixRowToStr(a[ri]);
            if (ri < b.length)
                mBRow = matrixRowToStr(b[ri]);
            if (ri < res.length)
                mResRow = matrixRowToStr(res[ri]);

            char asterixSmbI = ri != centerRowI ? ' ' : '*';
            char equalSmbI = ri != centerRowI ? ' ' : '=';
            System.out.printf("""
                    %s  %s  %s  %s  %s
                    """, mARow, asterixSmbI, mBRow, equalSmbI, mResRow);

        }
    }

    private static String matrixRowToStr(double[] mRow) {
        StringBuilder sb = new StringBuilder();
        for (double i : mRow)
            sb.append(String.format("%.1f", i)).append(" ");
        return sb.nodeToString();
    }
}
