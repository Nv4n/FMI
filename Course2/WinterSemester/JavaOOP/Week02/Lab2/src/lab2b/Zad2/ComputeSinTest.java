package lab2b.Zad2;

import java.util.Scanner;

public class ComputeSinTest {
    public static void main(String[] args) {
        ComputeSin calc = new ComputeSin(0.1);
        Scanner input = new Scanner(System.in);

        double sin = 0;
        for (int i = 1; (sin = calc.computeSin()) < 1 && sin >= 0; i++) {
            System.out.printf("X: %.3f\tsin(x): %.3f%n",
                    calc.getX(), sin);
            calc.setX(calc.getX() + 0.1);

            if (i % 20 == 0) {
                System.out.print("Please press return to continue...");
                input.nextLine();
            }
        }
    } // end main method
} // end class ComputeSinTest
