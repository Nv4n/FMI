package lab3.a.Zad5;


import javax.swing.*;
import java.util.Optional;

public class ComplexNumberTest {
    public static void main(String[] args) {
        Optional<String> input = Optional.ofNullable(JOptionPane.showInputDialog("Input imaginary part:"));
        double imaginaryInput = Double.parseDouble(input.orElse("0"));
        input = Optional.ofNullable(JOptionPane.showInputDialog("Input real part:"));
        double realInput = Double.parseDouble(input.orElse("0"));
        ComplexNumber number1 = new ComplexNumber(imaginaryInput, realInput);

        input = Optional.ofNullable(JOptionPane.showInputDialog("Input imaginary part:"));
        imaginaryInput = Double.parseDouble(input.orElse("0"));
        input = Optional.ofNullable(JOptionPane.showInputDialog("Input real part:"));
        realInput = Double.parseDouble(input.orElse("0"));
        ComplexNumber number2 = new ComplexNumber(imaginaryInput, realInput);

        printComplexNumber(number1);

        number1 = number1.add(number2);
        printComplexNumber(number1);
    }

    private static void printComplexNumber(ComplexNumber number) {
        JOptionPane.showMessageDialog(null,
                String.format("%.2f+%.2fi%nAngle: %.2f%nMagnitude: %.2f",
                        number.getRealPart(),
                        number.getImaginaryPart(),
                        number.getAngle(),
                        number.getMagnitude()));
    }
}
