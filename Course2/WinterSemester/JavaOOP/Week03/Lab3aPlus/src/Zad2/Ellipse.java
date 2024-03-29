package Zad2;

import javafx.scene.Group;
import javafx.scene.shape.Line;

public class Ellipse {
    private double x0;
    private double y0;

    private double a;
    private double b;

    public Ellipse(double a, double b, double width, double height) {
        setX0(width / 2);
        setY0(height / 2);
        setA(a);
        setB(b);
    }

    public double getX0() {
        return x0;
    }

    private void setX0(double x0) {
        this.x0 = x0;
    }

    public double getY0() {
        return y0;
    }

    private void setY0(double y0) {
        this.y0 = y0;
    }

    public double getA() {
        return a;
    }

    public void setA(double a) {
        this.a = a <= x0 ? a : 1;
    }

    public double getB() {
        return b;
    }

    public void setB(double b) {
        this.b = b <= y0 ? b : 1;
    }

    public void drawEllipse(Group group) {
        double prevX = getX(0);
        double prevY = getY(0);

        for (int i = 1; i <= 360; i++) {
            double x = getX(i);
            double y = getY(i);
            Line line = new Line(prevX, prevY, x, y);
            int r = getRandom();
            int g = getRandom();
            int b = getRandom();
            line.setStyle(String.format("-fx-stroke: rgb(%d,%d,%d)", r, g, b));
            prevX = x;
            prevY = y;

            group.getChildren().add(line);
        }
    }

    private static int getRandom() {
        return (int) (Math.random() * 255);
    }

    private double getX(int degree) {
        return a * Math.cos(degree) + x0;
    }

    private double getY(int degree) {
        return b * Math.sin(degree) + y0;
    }
}
