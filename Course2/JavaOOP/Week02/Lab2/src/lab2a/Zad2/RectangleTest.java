package lab2a.Zad2;

import javax.swing.*;
import java.util.Optional;

public class RectangleTest {
    public static void main(String[] args) {
        Rectangle rectangle1 = new Rectangle();

        Optional<String> width = Optional.ofNullable(JOptionPane.showInputDialog("Input width:"));
        Optional<String> height = Optional.ofNullable(JOptionPane.showInputDialog("Input height: "));
        Rectangle rectangle2 = new Rectangle(
                Double.parseDouble(width.orElse("1")),
                Double.parseDouble(height.orElse("1")));

        rectangle1.displayRectangleInfo();
        Rectangle.setColor(JOptionPane.showInputDialog("Input color: "));

        rectangle2.displayRectangleInfo();
    }
}
