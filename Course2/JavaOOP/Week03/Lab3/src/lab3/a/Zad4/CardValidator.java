package lab3.a.Zad4;

public class CardValidator {

    /**
     * Return true if the card number is valid
     */
    public static boolean isValid(long number) {
        int size = getSize(number);
        long prefix2Digits = getPrefix(number, 2);
        long prefix1Digit = getPrefix(prefix2Digits, 1);
        return size >= 13 && size <= 16
                && (prefix1Digit == 4 || prefix1Digit == 5 || prefix1Digit == 6 || prefix2Digits == 37)
                && sumOfDoubleEvenPlace(number) + sumOfOddPlace(number) % 10 == 0;
    }

    /**
     * Get the result from Step 2
     */
    public static int sumOfDoubleEvenPlace(long number) {
        int sum = 0;
        for (int i = 1; number != 0; i++) {
            if (i % 2 == 0) {
                int digit = getDigit((int) (2 * (number % 10)));
                sum += digit;
            }

            number /= 10;
        }
        return sum;
    }

    /**
     * Return this number if it is a single digit, otherwise,
     * return the sum of the two digits
     */
    public static int getDigit(int number) {
        return number < 10 ? number : number % 10 + 1;
    }

    /**
     * Return sum of odd-place digits in number
     */
    public static int sumOfOddPlace(long number) {
        int sum = 0;
        for (int i = 1; number != 0; i++) {
            if (i % 2 != 0) {
                int digit = (int) (number % 10);
                sum += digit;
            }

            number /= 10;
        }
        return sum;
    }

    /**
     * Return true if the digit d is a prefix for number
     */
    public static boolean prefixMatched(long number, int d) {
        return d == getPrefix(number, 1);
    }

    /**
     * Return the number of digits in d
     */
    public static int getSize(long d) {
        int size = 0;
        while (d != 0) {
            d /= 10;
            size++;
        }
        return size;
    }

    /**
     * Return the first k number of digits from number. If the
     * number of digits in number is less than k, return number.
     */
    public static long getPrefix(long number, int k) {
        long maxNumber = (long) Math.pow(10, k);
        while (number >= maxNumber)
            number /= 10;
        return number;
    }
}
