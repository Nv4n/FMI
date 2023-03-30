// Lab 2: Calculate2.java
// Perform simple calculations on three integers.

package labexercises.lab2;

import javax.swing.*;

public class Calculate2 {

    public static void main(String args[]) {
        String firstNumber;  // first string entered by user
        String secondNumber; // second string entered by user
        String thirdNumber;  // third string entered by user

        int number1; // first number
        int number2; // second number
        int number3; // third number

        int average;  // average of the numbers
        int largest;  // largest number
        int product;  // product of the numbers
        int smallest; // smallest number
        int sum;      // sum of the numbers

      /* write a series of statements to read in three numbers, convert them
         to integers, and assign them to number1, number2, and number3 */
        String input = JOptionPane.showInputDialog("Input first integer: ");
        number1 = Integer.parseInt(input);

        input = JOptionPane.showInputDialog("Input second integer: ");
        number2 = Integer.parseInt(input);

        input = JOptionPane.showInputDialog("Input third integer: ");
        number3 = Integer.parseInt(input);
        // initialize largest and smallest
        largest = number1;
        smallest = number2;

        // determine smallest and largest
      /* write code here that compares all three integers and sets the 
         largest and smallest accordingly */
        if (largest < number2) {
            largest = number2;
        } else if (largest < number3) {
            largest = number3;
        }

        if (smallest > number1) {
            smallest = number1;
        } else if (smallest > number3) {
            smallest = number3;
        }

        // perform calculations
        sum = number1 + number2 + number3;
//        /* write statements to calculate the product and the average */
        product = number1 * number2 * number3;
        average = sum / 3;
//
//        // create result string
        String result;
//      /* Write a statement that concatenates all the results into a single string
//         "result" that is displayed on line from line 44 of the template code */
        result = String.format("Largest number: %d%n" +
                "Smallest number: %d%n" +
                "Sum: %d%n" +
                "Product: %d%n" +
                "Average: %d%n", largest, smallest, sum, product, average);
        JOptionPane.showMessageDialog(new JFrame(), result);
        // Write a statement to output results

    }

} // end class Calculate2

 
 
