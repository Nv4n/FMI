package lab4.plus.Zad7;

import java.util.Arrays;
import java.util.Random;

public class ShuffleTest {
    private static final Random random = new Random();

    public static void main(String[] args) {
        int[][] m = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
        shuffle(m);
        System.out.println(Arrays.deepToString(m));
    }

    public static void shuffle(int[][] m) {
        int[][] result = new int[m.length][];
        int size = m.length;

        for (int i = 0; i < m.length; i++) {
            int index = random.nextInt(size);
            result[i] = m[index].clone();
            size--;

            for (int j = index; j < size; j++) m[j] = m[j + 1];
        }

        for (int i = 0; i < result.length; i++) {
            m[i] = result[i];
        }
    }
}
