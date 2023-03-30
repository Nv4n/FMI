package lab2b.Zad2;

public class ComputeSin {
    private double x;
    private final double EPSILON = 0.000001d;


    public ComputeSin(double x) {
        setX(x);
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double computeSin() {
        long currFac = 2 * 3; // 3!
        double currXProduct = x * x * x; // x^3
        int currMinusOne = -1; // (-1)^1;

        double prevSum = x; // first sum
        double currSum = -1 * Math.pow(x, 3); // 2nd sum
        double sin = prevSum + currSum;

        for (int i = 2; hasCorrectPrecision(prevSum, currSum); i++) {
            prevSum = currSum;

            currMinusOne *= -1;
            currFac = currFac * (2L * i) * (2L * i + 1); // (2*i + 1)!
            currXProduct *= x * x; // x^ (2*i+1)
            currSum = currMinusOne * currXProduct / currFac;

            sin += currSum;
        }
        return sin;
    }

    private boolean hasCorrectPrecision(double prevSum, double currSum) {
        return Math.abs(prevSum - currSum) < EPSILON;
    }
}
