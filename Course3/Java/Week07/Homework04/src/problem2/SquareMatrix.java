package problem2;

public class SquareMatrix {
    private int[][] dataArray;

    public SquareMatrix() {
        this(new int[1][1]);
    }

    public SquareMatrix(int[][] dataArray) {
        setDataArray(dataArray);
    }

    public SquareMatrix(SquareMatrix other) {
        this(other.dataArray);
    }

    public int[][] getDataArray() {
        int[][] tempArray = new int[dataArray.length][dataArray[0].length];
        for (int row = 0; row < dataArray.length; row++)
            for (int col = 0; col < dataArray[0].length; col++)
                tempArray[row][col] = dataArray[row][col];
        return tempArray;
    }

    public void setDataArray(int[][] dataArray) {
        if (dataArray.length == dataArray[0].length) {
            this.dataArray = new int[dataArray.length][dataArray[0].length];
            for (int row = 0; row < dataArray.length; row++)
                for (int col = 0; col < dataArray[0].length; col++)
                    this.dataArray[row][col] = dataArray[row][col];
        } else this.dataArray = new int[1][1];
    }

    public int findMaxSum() {
        int sum = Integer.MIN_VALUE;

        for (int row = 0; row < dataArray.length - 1; row++)
            for (int col = 0; col < dataArray[0].length - 1; col++) {
                int tempSum = dataArray[row][col] + dataArray[row][col + 1]
                        + dataArray[row + 1][col] + dataArray[row + 1][col + 1];

                if (tempSum > sum) sum = tempSum;
            }

        return sum;
    }

    public void printAll() {
        int maxSum = findMaxSum();
        System.out.printf("Maximum sum: %d%nSubmatrices with Maximum sum:%n", maxSum);
        for (int row = 0; row < dataArray.length - 1; row++)
            for (int col = 0; col < dataArray[0].length - 1; col++) {
                int tempSum = dataArray[row][col] + dataArray[row][col + 1]
                        + dataArray[row + 1][col] + dataArray[row + 1][col + 1];

                if (maxSum == tempSum) System.out.printf("[%d, %d]%n", row, col);
            }
    }


    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder();
        for (int[] row : dataArray) {
            for (int col : row) sb.append(col).append(" ");
            sb.append("\n");
        }
        return sb.toString();
    }
}
