package lab2a.Zad3;

public class VarietyTest {
    public static void main(String[] args) {
        int totalNumberCount = 0;
        int conditionNumberCount = 0;

        for (int firstDigit = 3; firstDigit <= 9; firstDigit++) {
            for (int secondDigit = 2; secondDigit <= 8; secondDigit++) {
                for (int thirdDigit = 4; thirdDigit <= 9; thirdDigit++) {
                    for (int fourthDigit = 1; fourthDigit <= 6; fourthDigit++) {
                        for (int fifthDigit = 6; fifthDigit <= 9; fifthDigit++) {

                            //Increment total numbers count;
                            totalNumberCount++;

                            //Get the number from last 2 digits to check if it's divisible by 4
                            int lastTwoDigits = (fourthDigit * 10) + fifthDigit;
                            //Sum all digits to check if its divisible by 3
                            int digitsSum = firstDigit + secondDigit + thirdDigit + fourthDigit + fifthDigit;

                            if (lastTwoDigits % 4 == 0 && digitsSum % 3 == 0)
                                conditionNumberCount++;
                        }
                    }
                }
            }
        }

        double chance = 100.0 * conditionNumberCount / totalNumberCount;
//        System.out.printf("""
//                Total number count is: %d  \s
//                Numbers under the conditions are: %d  \s
//                Chance is: %.2f%%  \s
//                %n""", totalNumberCount, conditionNumberCount, chance);

        String resultString = String.format(
                "Total number count is: %d%nNumbers under the conditions are: %d%nChance is: %.2f%%%n",
                totalNumberCount, conditionNumberCount, chance);
        System.out.println(resultString);
    }
}
