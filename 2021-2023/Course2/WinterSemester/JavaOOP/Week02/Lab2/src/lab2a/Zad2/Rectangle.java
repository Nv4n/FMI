package lab2a.Zad2;

import javax.swing.*;

public class Rectangle {
    private double width;
    private double height;
    private static String color;

    public Rectangle() {
        this(1, 1);
    }

    public Rectangle(double width, double height) {
        setWidth(width);
        setHeight(height);
        setColor("yellow");
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width > 0 ? width : 1;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height > 0 ? height : 1;
    }

    public static String getColor() {
        return color;
    }

    public static void setColor(String color) {
        Rectangle.color = color != null && !color.equals("")
                ? color.toLowerCase() : "yellow";
    }

    public double getArea() {
        return height * width;
    }

    public double getPerimeter() {
        return (height + width) * 2;
    }

    public void displayRectangleInfo() {
        JOptionPane.showMessageDialog(null,
                String.format("Width: %.2f; Height: %.2f; Color: %s %nArea: %.2f%nPerimeter: %.2f",
                        width, height, color, getArea(), getPerimeter()));
    }
}
