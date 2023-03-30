package exercises.b.Zad2;

public class Pi {
    private byte currMinusOne;

    private double pi;
    private int index;

    public Pi() {
        currMinusOne = 1; //1^0
        index = 1;
        pi = 4;
    }

    public double getPi() {
        return pi;
    }

    public int getIndex() {
        return index;
    }

    public void nextPi() {
        currMinusOne *= -1;
        pi = pi + (4.0 * currMinusOne) / (2 * ++index - 1);
    }
}
