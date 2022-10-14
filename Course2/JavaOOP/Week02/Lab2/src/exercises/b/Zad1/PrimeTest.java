package exercises.b.Zad1;

public class PrimeTest {
    private static final int N_LIMIT = 10_000;

    public static void main(String[] args) {
        Prime prime = new Prime();

        while (prime.getPrimeNumber() <= N_LIMIT) {
            System.out.println(prime.getPrimeNumber());
            prime.nextPrime();
        }

        System.out.printf("Time with divided by 2 is: %,d nanoseconds%nTime with sqrt is: %,d nanoseconds%n",
                prime.getDividedBy2Time(),
                prime.getSqrtTime());

    }
}
