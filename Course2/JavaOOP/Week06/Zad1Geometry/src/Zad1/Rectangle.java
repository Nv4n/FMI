package Zad1;

public class Rectangle extends Point {
    private Point lowRightCorner;

    public Rectangle() {
        this(new int[]{0, 0}, new int[]{1, 1});
    }

    public Rectangle(int[] startCoords, int[] lrcCoords) {
        super(startCoords);
        setLowRightCorner(new Point(lrcCoords));
    }

    public Rectangle(Point startCorner, Point endCorner) {
        this(startCorner.getCoordinates(),
                endCorner.getCoordinates());
    }

    public Rectangle(Rectangle other) {
        this(other.getCoordinates(),
                other.getLowRightCorner().getCoordinates());
    }

    public Point getLowRightCorner() {
        return new Point(lowRightCorner);
    }

    public void setLowRightCorner(Point lowRightCorner) {
        if (lowRightCorner != null)
            this.lowRightCorner = new Point(lowRightCorner);
        else
            this.lowRightCorner = new Point(new int[]{1, 1});
    }

    public double measure() {
        int x1 = this.getCoordinates()[0];
        int x2 = lowRightCorner.getCoordinates()[0];
        int y1 = this.getCoordinates()[1];
        int y2 = lowRightCorner.getCoordinates()[1];

        Line sideA = new Line(new int[]{x1, y1}, new int[]{x1, y2});
        Line sideB = new Line(new int[]{x1, y2}, new int[]{x2, y2});
        return 2 * (sideA.measure() + sideB.measure());
    }

    @Override
    public String toString() {
        return String.format("TLC %s\tLRC %s",
                super.toString(),
                this.lowRightCorner.printNode());
    }


}
