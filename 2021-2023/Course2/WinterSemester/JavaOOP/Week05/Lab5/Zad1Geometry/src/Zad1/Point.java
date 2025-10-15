package Zad1;

public class Point {
    private double x;
    private double y;

    public Point() {
        this(0, 0);
    }

    public Point(double x, double y) {
        setX(x);
        setY(y);
    }

    public Point(Point other) {
        this(other.getX(), other.getY());
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    @Override
    public String nodeToString() {
        return String.format("X: %.2f\tY: %.2f", x, y);
    }
}
