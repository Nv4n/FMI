package Zad1;

import javafx.scene.Group;
import javafx.scene.Parent;

public class Line {
    Point sPoint;
    Point ePoint;

    public Line() {
        this(new Point(), new Point());
    }

    public Line(Point sPoint, Point ePoint) {
        setStartPoint(sPoint);
        setEndPoint(ePoint);
    }

    public Line(Line other) {
        this(other.getStartPoint(), other.getEndPoint());
    }

    public Point getStartPoint() {
        return new Point(sPoint);
    }

    public void setStartPoint(Point sPoint) {
        if (sPoint != null)
            this.sPoint = new Point(sPoint);
        else
            this.sPoint = new Point();
    }

    public Point getEndPoint() {
        return new Point(ePoint);
    }

    public void setEndPoint(Point ePoint) {
        if (ePoint != null)
            this.ePoint = new Point(ePoint);
        else
            this.ePoint = new Point();
    }

    @Override
    public String toString() {
        return String.format("Start %s\tEnd %s",
                sPoint.toString(),
                ePoint.nodeToString());
    }

    public void draw(Group pane) {
        javafx.scene.shape.Line line = new javafx.scene.shape.Line(
                sPoint.getX(),
                sPoint.getY(),
                ePoint.getX(),
                ePoint.getY());
        line.setStyle("-fx-stroke: darkorange");
        pane.getChildren().add(line);
    }
}
