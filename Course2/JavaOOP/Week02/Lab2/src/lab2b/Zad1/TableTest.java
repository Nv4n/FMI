package lab2b.Zad1;

import javax.swing.*;
import java.util.Optional;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;

public class TableTest {
    public static void main(String[] args) {
        Optional<String> start = Optional.ofNullable(JOptionPane.showInputDialog("Input start of interval:"));
        Optional<String> end = Optional.ofNullable(JOptionPane.showInputDialog("Input end of interval:"));
        Optional<String> steps = Optional.ofNullable(JOptionPane.showInputDialog("Input steps:"));
        Table table = new Table(
                parseDouble(start.orElse("1")),
                parseDouble(end.orElse("2")),
                parseInt("1"));
    }
}
