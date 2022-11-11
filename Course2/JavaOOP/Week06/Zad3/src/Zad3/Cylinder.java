package Zad3;

import org.jetbrains.annotations.NotNull;

public class Cylinder extends Circle {
    private int height;

    public Cylinder() {
        super();
        setHeight(1);
    }

    public Cylinder(int x, int y, int radius, int height) {
        super(x, y, radius);
        setHeight(height);
    }

    public Cylinder(@NotNull Circle other, int height) {
        super(other);
        setHeight(height);
    }

    public Cylinder(@NotNull Cylinder other) {
        this(other.getX(), other.getY(), other.getRadius(), other.getHeight());
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height > 0 ? height : 1;
    }

    @Override
    public int compareTo(@NotNull Object o) {
        if (o instanceof Cylinder)
            if (((Cylinder) o).height > this.height)
                return 1 + super.compareTo(new Circle(((Cylinder) o).getX(), ((Cylinder) o).getY(), ((Cylinder) o).getRadius()));
            else if (((Cylinder) o).height < this.height)
                return -1 + super.compareTo(new Circle(((Cylinder) o).getX(), ((Cylinder) o).getY(), ((Cylinder) o).getRadius()));
            else
                return super.compareTo(new Circle(((Cylinder) o).getX(), ((Cylinder) o).getY(), ((Cylinder) o).getRadius()));
        return -1;
    }
}
