package debuggingproblem;//   Debugging Problem /

import javax.swing.*;
import java.util.Optional;

public class Arithmetic {
    public static void main(String[] args) {
        Optional<String> firstNumber, secondNumber, thirdNumber;
        int num1, num2, num3, sum, product, average;

        /*Using good practices and
        extracting into a method duplicated code*/
        firstNumber = getInput("Enter first integer:");
        secondNumber = getInput("Enter second integer:");
        thirdNumber = getInput("Enter third integer: ");

        num1 = parseInput(firstNumber);
        num2 = parseInput(secondNumber);
        num3 = parseInput(thirdNumber);

        sum = num1 + num2 + num3;
        product = num1 * num2 * num3;
        average = (num1 + num2 + num3) / 3;

        JOptionPane.showMessageDialog(null, "The sum is " + sum +
                        "\nThe product is " + product + "\nThe average is " + average,
                "Results", JOptionPane.PLAIN_MESSAGE);
    }

    private static Optional<String> getMenuInput(String message) {
        return JOptionPane.showInputDialog(message).describeConstable();
    }

    private static int parseInput(Optional<String> input) {
        return Integer.parseInt(input.orElse("1"));
    }

} // end class Arithmetic

