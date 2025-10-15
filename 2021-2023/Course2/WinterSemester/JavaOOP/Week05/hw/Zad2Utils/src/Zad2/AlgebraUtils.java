package Zad2;

public class AlgebraUtils {
    public static void main(String[] args) {
    }

    public static double[][] multiplyMatrix(double[][] a, double[][] b) {
        if (a[0].length != b.length)
            throw new IllegalArgumentException(
                    "MatrixA columns are different length than MatrixB rows");
        double[][] result = new double[a.length][b[0].length];

        for (int ri = 0; ri < result.length; ri++)
            for (int ci = 0; ci < result[0].length; ci++)
                for (int i = 0; i < a[0].length; i++)
                    result[ri][ci] += a[ri][i] * b[i][ci];

        return result;
    }
}
