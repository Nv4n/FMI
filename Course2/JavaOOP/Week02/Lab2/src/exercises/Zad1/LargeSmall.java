package exercises.Zad1;
// LargeSmall.java
// Calculates the largest and smallest
// of five integers entered one at a time.

// Java core packages

import java.awt.*;
import java.util.Optional;

// Java extension packages
import javax.swing.*;

public class LargeSmall {

    // Compute the smallest and the largest among 4 input numbers
    // obtain numerical input and determine results

    public static void main(String[] args) {
        String smallString;  // smallest number string
        String largeString;  // largest number string
        Optional<String> input;     // string entered by user
        int largest, smallest; // largest and smallest integers

        // variables to store integers input by user
        int firstNumber, secondNumber, thirdNumber,
                fourthNumber, fifthNumber;


        // obtain first value
        input = getInput("Enter first number :");
        firstNumber = getNumber(input);
        /* Read second number from user and assign it to variable secondNumber */
        input = getInput("Enter second number: ");
        secondNumber = getNumber(input);

      /* Compare variables smallest and largest
      with the input and set them appropriately */
        largest = getLargest(firstNumber, secondNumber);
        smallest = getSmallest(firstNumber, secondNumber);

      /* Perform the same steps with the
      third, fourth and fifth values */
        input = getInput("Enter third number: ");
        thirdNumber = getNumber(input);
        largest = getLargest(largest, thirdNumber);
        smallest = getSmallest(smallest, thirdNumber);

        input = getInput("Enter fourth number: ");
        fourthNumber = getNumber(input);
        largest = getLargest(largest, fourthNumber);
        smallest = getSmallest(smallest, fourthNumber);

        input = getInput("Enter fifth number: ");
        fifthNumber = getNumber(input);
        largest = getLargest(largest, fifthNumber);
        smallest = getSmallest(smallest, fifthNumber);
      /* Create a formatted output String  with the obtained  
         smallest and largest input numbers*/
        smallString = String.format("Smallest number: %d", smallest);
        largeString = String.format("Largest number: %d", largest);

        // output string
        String dataString = String.format("""
                        Numbers: %5d\t%5d\t%5d\t%5d\t%5d \s
                        %s \s
                        %s \s
                        """,
                firstNumber, secondNumber, thirdNumber, fourthNumber, fifthNumber,
                smallString, largeString);
        /* Output the formatted output String  using a dialog box */
        JOptionPane.showMessageDialog(null, dataString, "Results", JOptionPane.INFORMATION_MESSAGE);
    }// end method main

    private static int getSmallest(int smallest, int secondNumber) {
        return smallest > secondNumber ? secondNumber : smallest;
    }

    private static int getLargest(int largest, int secondNumber) {
        return largest < secondNumber ? secondNumber : largest;
    }

    private static int getNumber(Optional<String> input) {
        return Integer.parseInt(input.orElse("0"));
    }

    private static Optional<String> getInput(String message) {
        return Optional.ofNullable(JOptionPane.showInputDialog(message));
    }
}  // end class LargeSmall

