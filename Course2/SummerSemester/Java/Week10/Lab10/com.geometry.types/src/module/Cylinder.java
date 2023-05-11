package module;

public class Cylinder extends Circle {
    private int height;

    public Cylinder() {
        super();
        setHeight(10);
    }

    public Cylinder(int x, int y, int radius, int height) {
        super(x, y, radius);
        setHeight(height);
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = Math.max(height, 1);
    }

    @Override
    public int compareTo(Object obj) {
        if (obj == null) return 1;
        if (!(obj instanceof Cylinder c2)) return 1;

        if (getX() > c2.getX()
                || getX() == c2.getX() && getY() > c2.getY()
                || getX() == c2.getX() && getY() == c2.getY() && getRadius() > c2.getRadius())
            return 1;
        else if (getX() == c2.getX() && getY() == c2.getY() && getRadius() == c2.getRadius())
            if (this.height > c2.height) return 1;
            else if (this.height == c2.height) return 0;
        return -1;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Cylinder{");
        sb.append(super.toString());
        sb.append(", height=").append(height);
        sb.append('}');
        return sb.toString();
    }
}
