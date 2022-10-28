package lab4.a.Zad8;

public class MathArray {
    private int[][] table;
    private int[] row;

    public MathArray() {
        this(new int[][]{ //table
                {3, 4, 5, 6, 3},
                {2, 1, 2, 1, 1},
                {3, 2, 1, 4, 9},
                {1, 0, 0, 1, 1},
                {9, 2, 6, 4, 9}
        }, new int[]{2, 1, 2, 3, 4}); //row
    }

    public MathArray(int[][] table, int[] row) {
        setTable(table);
        setRow(row);
    }

    public void setTable(int[][] table) {
        for (int[] row : table)
            if (table.length != row.length)
                throw new IllegalArgumentException("Row length is invalid: " + row.length);
        this.table = table;
    }

    public void setRow(int[] row) {
        if (row.length != table.length)
            throw new IllegalArgumentException("Row length is invalid: " + row.length);
        this.row = row;
    }

    public int[] multiplyMatrixByRow() {
        int[] result = new int[table.length];
        for (int ci = 0; ci < table.length; ci++)
            for (int ri = 0; ri < table.length; ri++)
                result[ci] += row[ri] * table[ri][ci];
        return result;
    }

    public int[][] squareMatrix() {
        int[][] result = new int[table.length][table.length];
        for (int ci = 0; ci < table.length; ci++)
            for (int ri = 0; ri < table.length; ri++)
                result[ci][ri] += table[ri][ci] * table[ci][ri];
        return result;
    }

    public double scalarProduct() {
        double result = 0;
        for (double i : row)
            result += i * i;
        return result;
    }

    public int[][] transposeMatrix() {
        int[][] result = new int[table.length][table.length];
        for (int ri = 0; ri < table.length; ri++)
            for (int ci = 0; ci < table.length; ci++)
                result[ci][ri] = table[ri][ci];
        return result;
    }

    public double matrixTrace() {
        double result = 0;
        for (int i = 0; i < table.length; i++)
            result += table[i][i] + row[i];
        return result;
    }

    public String toString(int[] matrix) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < matrix.length; i++) {
            result.append(matrix[i]);
            if (i + 1 < matrix.length)
                result.append(", ");
        }
        return result.toString();
    }

    public String toString(int[][] matrix) {
        StringBuilder result = new StringBuilder();
        for (int[] ints : matrix) {
            result.append(this.toString(ints));
            result.append("\n");
        }
        return result.toString();
    }

    public String toString() {
        return "table\n" +
                this.toString(table) +
                "row\n" +
                this.toString(row);
    }

}
