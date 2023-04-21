package problem1;

import javafx.scene.Group;
import javafx.scene.Parent;

public class Line {
    private Point sPoint;
    private Point ePoint;

    public Line() {
        this(new Point(), new Point(10, 10));
    }

    public Line(Point sPoint, Point ePoint) {
        setSPoint(sPoint);
        setEPoint(ePoint);
    }

    public Line(Line other) {
        this(other.getSPoint(), other.getEPoint());
    }

    final public Point getSPoint() {
        return new Point(sPoint);
    }

    final public void setSPoint(Point sPoint) {
        this.sPoint = sPoint != null
                ? new Point(sPoint)
                : new Point();
    }

    final public Point getEPoint() {
        return new Point(ePoint);
    }

    final public void setEPoint(Point ePoint) {
        this.ePoint = ePoint != null
                ? new Point(ePoint)
                : new Point();
    }

    public void draw(Group pane) {
        javafx.scene.shape.Line line =
                new javafx.scene.shape.Line(
                        sPoint.getX(),
                        sPoint.getY(),
                        ePoint.getX(),
                        ePoint.getY());
        pane.getChildren().add(line);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Line{");
        sb.append("sPoint=").append(sPoint.toString());
        sb.append(", ePoint=").append(ePoint.toString());
        sb.append('}');
        return sb.toString();
    }
}
