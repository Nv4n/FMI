package lab3.a.Zad3;

public class CalculateCos {
    private double x;
    private double epsilon;

    private boolean isCosCalculated;

    private double cos;

    public CalculateCos(double x, double epsilon) {
        setX(x);
        setEpsilon(epsilon);
        isCosCalculated = false;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        isCosCalculated = false;
        this.x = x;
    }

    public double getEpsilon() {
        return epsilon;
    }

    public void setEpsilon(double epsilon) throws IllegalArgumentException {
        if (epsilon > 0 && epsilon < 1)
            this.epsilon = epsilon;
        else
            throw new IllegalArgumentException(String.format("Invalid epsilon value: %f", epsilon));
    }

    public double getCos() {
        if (!isCosCalculated)
            calculateCos();

        return cos;
    }

    public void calculateCos() {
        if (isCosCalculated)
            return;

        long currFac = 2; // 2!
        double currXProduct = x * x; // x^2
        int currMinusOne = -1;

        double prevSum = 1; // first sum
        double currSum = currMinusOne * currXProduct / currFac; // 2nd sum
        cos = prevSum + currSum;

        // FIXME: 10/17/2022
        //  Doesn't calculate cos(x) correctly

        for (int i = 4; hasCorrectPrecision(prevSum, currSum); i += 2) {
            prevSum = currSum;

            currMinusOne *= -1;
            currFac *= (long) i * (i - 1); // i!
            currXProduct *= (x * x); // x^i
            currSum = currMinusOne * currXProduct / currFac;

            cos += currSum;
        }
        isCosCalculated = true;
    }


    private boolean hasCorrectPrecision(double prevSum, double currSum) {
        return Math.abs(currSum - prevSum) < epsilon;
    }
}
