package exercises.b.Zad1;

public class Prime {
    private long sqrtTime;
    private long dividedBy2Time;
    private int primeNumber;

    public Prime() {
        primeNumber = 2;
        sqrtTime = 0;
        dividedBy2Time = 0;
    }

    public int getPrimeNumber() {
        return primeNumber;
    }

    public long getSqrtTime() {
        return sqrtTime;
    }

    public long getDividedBy2Time() {
        return dividedBy2Time;
    }

    public void nextPrime() {
        for (int i = primeNumber + 1; ; i++) {
            if (isPrime(i)) {
                primeNumber = i;
                return;
            }
        }
    }

    private boolean isPrime(int number) {
        boolean flag = true;
        long start = System.nanoTime();
        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) {
                flag = false;
                break;
            }
        }

        long end = System.nanoTime();
        sqrtTime += (end - start);
        start = System.nanoTime();
        for (int i = 2; i <= number / 2; i++) {
            if (number % i == 0) {
                flag = false;
                break;
            }
        }

        end = System.nanoTime();
        dividedBy2Time += (end - start);
        return flag;
    }

}
