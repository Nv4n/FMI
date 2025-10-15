package Zad1;

import java.util.ArrayList;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        // 0.5 per egg
        // 1 out of 10 pics per egg
        // budget: 7
        // Need 10 different eggs
        ArrayList<Integer> eggsCollected = new ArrayList<>();
        Random eggGenerator = new Random();

        for (int distinct = 0; distinct < 10; ) {
            int currEgg = eggGenerator.nextInt(10) + 1;
            if (!eggsCollected.contains(currEgg))
                distinct++;
            eggsCollected.add(currEgg);
        }

        System.out.printf("""
                Total eggs: %d
                Total price: %.2f
                Was our budget enough: %b
                """, eggsCollected.size(), eggsCollected.size() * 0.5, eggsCollected.size() * 0.5 <= 7);
    }
}
