package com.problem3;

import java.text.NumberFormat;
import java.util.Random;

public class GetRandomNumber {
    private static Random generator;

    public static void main(String[] args) {
        generator = new Random();
        NumberFormat nf = NumberFormat.getPercentInstance();
        nf.setMinimumFractionDigits(1);
        nf.setMaximumFractionDigits(2);

        int onesCount = 0;
        int twosCount = 0;
        int threesCount = 0;
        int iterations = 10_000;

        getPercentageChanceForEachNumber(nf, onesCount, twosCount, threesCount, iterations);

        iterations = 60_000;
        getPercentageChanceForEachNumber(nf, onesCount, twosCount, threesCount, iterations);
    }

    private static void getPercentageChanceForEachNumber(NumberFormat nf, int onesCount, int twosCount, int threesCount, int iterations) {
        for (int i = 0; i < iterations; i++) {
            int current = drawRandomNumber();
            switch (current) {
                case 1 -> onesCount++;
                case 2 -> twosCount++;
                case 3 -> threesCount++;
            }
        }

        double chanceForOne = 1.0 * onesCount / iterations;
        double chanceForTwo = 1.0 * twosCount / iterations;
        double chanceForThree = 1.0 * threesCount / iterations;
        System.out.printf("""
                        Loop of %d iterations
                        Percentage for 1: %s
                        Percentage for 2: %s
                        Percentage for 3: %s
                                                
                        """,
                iterations,
                nf.format(chanceForOne),
                nf.format(chanceForTwo),
                nf.format(chanceForThree));
    }

    private static int drawRandomNumber() {
        int chancePercent = generator.nextInt(0, 100) + 1;
        if (chancePercent <= 20) return 1;
        else if (chancePercent <= 50) return 2;
        else return 3;
    }
}
