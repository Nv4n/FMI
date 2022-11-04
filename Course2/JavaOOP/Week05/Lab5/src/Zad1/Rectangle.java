package Zad1;

import javafx.scene.Group;

public class Rectangle {
    private Point uPoint;
    private double width;
    private double height;

    public Rectangle() {
        this(new Point(), 10, 10);
    }

    public Rectangle(Point upperPoint, double width, double height) {
        setUPoint(upperPoint);
        setWidth(width);
        setHeight(height);
    }

    public Rectangle(Rectangle other) {
        this(other.getUPoint(), other.getWidth(), other.getHeight());
    }

    public Point getUPoint() {
        return new Point(uPoint);
    }

    public void setUPoint(Point uPoint) {
        if (uPoint != null)
            this.uPoint = new Point(uPoint);
        else
            this.uPoint = new Point();
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width > 1 ? width : 10;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height > 1 ? height : 10;
    }

    @Override
    public String toString() {
        return String.format("Upper point\t%s\tWidth: %.2f\tHeight: %.2f",
                uPoint.toString(),
                width,
                height);
    }

    public void draw(Group pane) {
        javafx.scene.shape.Rectangle rect = new javafx.scene.shape.Rectangle(
                uPoint.getX(),
                uPoint.getY(),
                width,
                height);
        rect.setStyle("-fx-fill: transparent;-fx-stroke: black");
        pane.getChildren().add(rect);
    }
}
