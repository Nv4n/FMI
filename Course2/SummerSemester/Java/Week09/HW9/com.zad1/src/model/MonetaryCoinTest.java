package model;

import java.util.Random;

public class MonetaryCoinTest {
    public static void main(String[] args) {
        Random rand = new Random();
        MonetaryCoin[] coins = new MonetaryCoin[5];
        Face[] faces = Face.values();
        int[] values = new int[]{1, 2, 5, 10, 20, 50};
        for (int i = 0; i < coins.length; i++) {
            Face face = faces[rand.nextInt(0, faces.length)];
            int value = values[rand.nextInt(0, values.length)];
            coins[i] = new MonetaryCoin(face, value);
        }

        for (MonetaryCoin coin : coins) System.out.println(coin);
        System.out.println("\nAfter flip");
        coins[rand.nextInt(0, coins.length)].flip();
        for (MonetaryCoin coin : coins) System.out.println(coin);
    }
}