package lab2a.Zad1;

import javax.swing.*;
import java.util.Optional;

public class TestConvert {
    public static void main(String[] args) {

        Optional<String> input = Optional.ofNullable(JOptionPane.showInputDialog("Input Celsius:"));
        Celsius celsius = new Celsius(Double.parseDouble(input.orElse("0")));

        input = Optional.ofNullable(JOptionPane.showInputDialog("Input Fahrenheit: "));
        Fahrenheit fahrenheit = new Fahrenheit(Double.parseDouble(input.orElse("0")));

        JOptionPane.showMessageDialog(null,
                String.format("%.2f C is:%n%.2f F", celsius.getCelsius(), celsius.convertToFahrenheit()),
                "Celsius result", JOptionPane.PLAIN_MESSAGE);
        JOptionPane.showMessageDialog(null,
                String.format("%.2f F is:%n%.2f C", fahrenheit.getFahrenheit(), fahrenheit.convertToCelsius()),
                "Fahrenheit result", JOptionPane.PLAIN_MESSAGE);

    }
}
