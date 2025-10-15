package Zad3;

import org.jetbrains.annotations.NotNull;

public class Circle extends Point {
    private int radius;

    public Circle() {
        super();
        setRadius(1);
    }

    public Circle(int x, int y, int radius) {
        super(x, y);
        setRadius(radius);
    }

    public Circle(@NotNull Point other, int radius) {
        this(other.getX(), other.getY(), radius);
    }

    public Circle(@NotNull Circle other) {
        this(other.getX(), other.getY(), other.getRadius());
    }

    public int getRadius() {
        return radius;
    }

    public void setRadius(int radius) {
        this.radius = radius > 0 ? radius : 1;
    }

    @Override
    public int compareTo(@NotNull Object o) {
        if (o instanceof Circle)
            if (((Circle) o).radius > this.radius)
                return 1 + super.compareTo(new Point(((Circle) o).getX(), ((Circle) o).getY()));
            else if (((Circle) o).radius < this.radius)
                return -1 + super.compareTo(new Point(((Circle) o).getX(), ((Circle) o).getY()));
            else
                return super.compareTo(new Point(((Circle) o).getX(), ((Circle) o).getY()));
            
        return -1;
    }
}
