package problem1;

public class Point {
    private double x;
    private double y;

    public Point() {
        this(1, 1);
    }

    public Point(double x, double y) {
        setX(x);
        setY(y);
    }

    public Point(Point other) {
        this(other.getX(), other.getY());
    }


    final public double getX() {
        return x;
    }

    final public void setX(double x) {
        this.x = x >= 0 ? x : 1;
    }

    final public double getY() {
        return y;
    }

    final public void setY(double y) {
        this.y = y >= 0 ? y : 1;
    }

    @Override
    public String toString() {
        return String.format("{x= %.3f, y= %.3f}", x, y);
    }
}
