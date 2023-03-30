package Zad1;

public class Line extends Point {
    private Point ePoint;

    public Line() {
        this(new int[]{0, 0}, new int[]{1, 1});
    }

    public Line(int[] sCoords, int[] eCoords) {
        super(sCoords);
        setEndPoint(new Point(eCoords));
    }

    public Line(Point sPoint, Point ePoint) {
        this(sPoint.getCoordinates(), ePoint.getCoordinates());
    }

    public Line(Line other) {
        this(other.getCoordinates(), other.getEndPoint().getCoordinates());
    }

    public Point getEndPoint() {
        return new Point(ePoint);
    }

    public void setEndPoint(Point ePoint) {
        if (ePoint != null)
            this.ePoint = new Point(ePoint);
        else
            this.ePoint = new Point(new int[]{1, 1});
    }

    public double measure() {
        int x1 = this.getCoordinates()[0];
        int x2 = ePoint.getCoordinates()[0];
        int y1 = this.getCoordinates()[1];
        int y2 = ePoint.getCoordinates()[1];

        return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    @Override
    public String toString() {
        return String.format("Start %s\tEnd %s", super.toString(), ePoint.nodeToString());
    }
}
