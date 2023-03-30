package lab2b.Zad3;

public class PerfectTest {
    private static final int NUMBER_PER_LINE = 5;
    private static final int NUMBER_OF_PERFECTS = 100000;

    public static void main(String[] args) {
        printAllPerfectNumbers();
    }

    public static boolean isPerfect(int number) {
        int dividersSum = 0;
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                dividersSum += i;
            }
        }

        return dividersSum == number;
    }

    public static void showMultipliers(int number) {
        int numberPerLineCountdown = NUMBER_PER_LINE;
        for (int i = 1; i <= number / 2; i++) {
            if (numberPerLineCountdown == 0) {
                System.out.printf("%n");
                numberPerLineCountdown = NUMBER_PER_LINE;
            }

            if (number % i == 0) {
                System.out.printf("%d\t", i);
                numberPerLineCountdown--;
            }
        }
    }

    public static void printAllPerfectNumbers() {
        for (int i = 1; i <= NUMBER_OF_PERFECTS; i++) {
            if (isPerfect(i)) {
                System.out.printf("%d 's multipliers:%n", i);
                showMultipliers(i);
                System.out.println();
            }
        }
    }
}

