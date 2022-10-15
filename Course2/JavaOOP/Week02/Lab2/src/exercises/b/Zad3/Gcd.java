package exercises.b.Zad3;

public class Gcd {
    private int number1;
    private int number2;
    private int gcdNumber;
    private boolean isGcdCalculated;

    public Gcd(int number1, int number2) {
        setNumber1(number1);
        setNumber2(number2);
        isGcdCalculated = false;
    }

    public int getNumber1() {
        return number1;
    }

    public void setNumber1(int number1) {
        isGcdCalculated = false;
        this.number1 = number1 >= 0 ? number1 : number1 * (-1);
    }

    public int getNumber2() {
        return number2;
    }

    public void setNumber2(int number2) {
        isGcdCalculated = false;
        this.number2 = number2 >= 0 ? number2 : number2 * (-1);
    }

    public int getGcdNumber() {
        //Validate if the GCD is calculated
        if (!isGcdCalculated) {
            //Calculate gcd if it isn't
            gcdNumber = gcd();
            isGcdCalculated = true;
        }
        return gcdNumber;
    }

    private int gcd() {
        for (int gcd = getFirstDivider(); gcd >= 1; --gcd) {
            if (number2 % gcd == 0 && number1 % gcd == 0)
                return gcd;
        }
        return 0;
    }

    private int getFirstDivider() {
        int smallestNumber;
        int largestNumber;

        if (number2 > number1) {
            largestNumber = number2;
            smallestNumber = number1;
        } else {
            largestNumber = number1;
            smallestNumber = number2;
        }
        return Math.min(smallestNumber, (int) Math.sqrt(largestNumber));
    }
}