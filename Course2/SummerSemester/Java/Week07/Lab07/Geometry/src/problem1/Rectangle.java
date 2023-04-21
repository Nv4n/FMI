package problem1;

import javafx.scene.Group;
import javafx.scene.paint.Paint;

public class Rectangle {
    private Point uPoint;
    private double width;
    private double height;

    public Rectangle() {
        this(new Point(), 10, 10);
    }

    public Rectangle(Point uPoint, double width, double height) {
        setUPoint(uPoint);
        setWidth(width);
        setHeight(height);
    }

    public Rectangle(Rectangle other) {
        this(other.getUPoint(), other.getWidth(), other.getHeight());
    }

    final public Point getUPoint() {
        return new Point(uPoint);
    }

    final public void setUPoint(Point uPoint) {
        this.uPoint = uPoint != null
                ? new Point(uPoint)
                : new Point();
    }

    final public double getWidth() {
        return width;
    }

    final public void setWidth(double width) {
        this.width = width > 0 ? width : 10;
    }

    final public double getHeight() {
        return height;
    }

    final public void setHeight(double height) {
        this.height = height > 0 ? height : 10;
    }

    public void draw(Group pane) {
        javafx.scene.shape.Rectangle rect =
                new javafx.scene.shape.Rectangle(
                        uPoint.getX(),
                        uPoint.getY(),
                        width,
                        height);
        rect.setFill(Paint.valueOf("transparent"));
        rect.setStroke(Paint.valueOf("black"));
        pane.getChildren().add(rect);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Rectangle{");
        sb.append("uPoint=").append(uPoint.toString());
        sb.append(", width=").append(width);
        sb.append(", height=").append(height);
        sb.append('}');
        return sb.toString();
    }
}
