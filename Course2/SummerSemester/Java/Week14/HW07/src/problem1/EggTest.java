package problem1;

import java.util.Random;
import java.util.TreeSet;

public class EggTest {
    public static void main(String[] args) {
        TreeSet<Integer> egss = new TreeSet<>();
        Random random = new Random();
        int buys = 0;
        while (egss.size() < 10) {
            buys++;
            egss.add(random.nextInt(0, 10));
        }
        System.out.printf("Bought eggs: %d, Price: %.2f", buys, buys * 0.5);
    }
}
