package exercises;// LargeSmall.java
// Calculates the largest and smallest
// of five integers entered one at a time.

// Java core packages

import java.awt.*;

// Java extension packages
import javax.swing.*;

public class LargeSmall {

    // Compute the smallest and the largest among 4 input numbers
    // obtain numerical input and determine results

    public static void main(String[] args) {
        String dataString;   // output string
        String smallString;  // smallest number string
        String largeString;  // largest number string
        String input;     // string entered by user
        int largest, smallest; // largest and smallest integers

        // variables to store integers input by user
        int firstNumber, secondNumber, thirdNumber,
                fourthNumber, fifthNumber;


        // obtain first value
        input = JOptionPane.showInputDialog("Enter first number :");
        firstNumber = Integer.parseInt(input);

        /* Read second number from user and assign it to variable secondNumber */

      /* Compare variables smallest and largest 
      with the input and set them appropriately */ 

      /* Perform the same steps with the
      third, fourth and fifth values */
        
      /* Create a formatted output String  with the obtained  
         smallest and largest input numbers*/

        /* Output the formatted output String  using a dialog box */

        // end method main
    }
}  // end class LargeSmall

