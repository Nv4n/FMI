package Zad3;

import org.jetbrains.annotations.NotNull;

public class Point extends Shape {
    private int x;
    private int y;

    public Point() {
        this(0, 0);
    }

    public Point(int x, int y) {
        setX(x);
        setY(y);
    }

    public Point(@NotNull Point other) {
        this(other.getX(), other.getY());
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = Math.max(x, 0);
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = Math.max(y, 0);
    }

    @Override
    public int compareTo(@NotNull Object o) {
        if (o instanceof Point)
            if (((Point) o).getX() > this.x
                    || ((Point) o).getY() > this.y)
                return 1;
            else if (((Point) o).getX() < this.x
                    || ((Point) o).getY() < this.y)
                return -1;
            else return 0;
        return -1;
    }
}
