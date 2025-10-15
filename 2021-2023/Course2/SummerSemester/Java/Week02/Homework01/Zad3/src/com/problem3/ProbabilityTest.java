package com.problem3;

public class ProbabilityTest {
    public static void main(String[] args) {
        int totalNumberCount = 0;
        int conditionNumberCount = 0;

        for (int firstDigit = 1; firstDigit <= 6; firstDigit++) {
            for (int secondDigit = 4; secondDigit <= 8; secondDigit++) {
                for (int thirdDigit = 3; thirdDigit <= 7; thirdDigit++) {
                    for (int fourthDigit = 1; fourthDigit <= 9; fourthDigit++) {
                        for (int fifthDigit = 1; fifthDigit <= 8; fifthDigit++) {

                            //Increment total numbers count;
                            totalNumberCount++;

                            //Get the number from last 2 digits to check if it's dividable by 4
                            int lastTwoDigits = (fourthDigit * 10) + fifthDigit;
                            //Sum all digits to check if it's dividable by 3
                            int digitsSum = firstDigit + secondDigit + thirdDigit + fourthDigit + fifthDigit;

                            //If dividable by both
                            if (lastTwoDigits % 4 == 0 && digitsSum % 3 == 0)
                                conditionNumberCount++;
                        }
                    }
                }
            }
        }

        double chance = 100.0 * conditionNumberCount / totalNumberCount;

        String resultString = String.format(
                "Total number count is: %d%nNumbers under the conditions are: %d%nChance is: %.2f%%%n",
                totalNumberCount, conditionNumberCount, chance);
        System.out.println(resultString);
    }
}
