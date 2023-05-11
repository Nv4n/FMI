package module;

public class Point implements Comparable {
    private int x;
    private int y;

    public Point() {
        setX(10);
        setY(10);
    }

    public Point(int x, int y) {
        setX(x);
        setY(y);
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
    public int compareTo(Object obj) {
        if (obj == null) return 1;
        if (!(obj instanceof Point p2)) return 1;

        if (this.x > p2.x || this.x == p2.x && this.y > p2.y) return 1;
        else if (this.x == p2.x && this.y == p2.y) return 0;
        return -1;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Point{");
        sb.append("x=").append(x);
        sb.append(", y=").append(y);
        sb.append('}');
        return sb.toString();
    }
}
