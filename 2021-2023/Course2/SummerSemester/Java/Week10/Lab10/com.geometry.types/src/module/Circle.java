package module;

public class Circle extends Point {
    private int radius;

    public Circle() {
        super();
        setRadius(5);
    }

    public Circle(int x, int y, int radius) {
        super(x, y);
        setRadius(radius);
    }

    public int getRadius() {
        return radius;
    }

    public void setRadius(int radius) {
        this.radius = Math.max(radius, 1);
    }

    @Override
    public int compareTo(Object obj) {
        if (obj == null) return 1;
        if (!(obj instanceof Circle c2)) return 1;

        if (getX() > c2.getX()
                || getX() == c2.getX() && getY() > c2.getY())
            return 1;
        else if (getX() == c2.getX() && getY() == c2.getY()) {
            if (this.radius > c2.radius) return 1;
            else if (this.radius == c2.radius) return 0;
        }
        return -1;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Circle{");
        sb.append(super.toString());
        sb.append(", radius=").append(radius);
        sb.append('}');
        return sb.toString();
    }
}
