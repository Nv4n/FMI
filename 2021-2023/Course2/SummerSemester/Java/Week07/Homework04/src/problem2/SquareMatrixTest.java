package problem2;

import java.util.Scanner;

public class SquareMatrixTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int size = input.nextInt();
        if (size < 2 || size > 12) {
            System.out.println("Invalid size");
            return;
        }

        int[][] matrix = new int[size][size];
        for (int row = 0; row < size; row++)
            for (int col = 0; col < size; col++)
                matrix[row][col] = input.nextInt();

        SquareMatrix sqrMatrix = new SquareMatrix(matrix);
        sqrMatrix.printAll();
    }
}
