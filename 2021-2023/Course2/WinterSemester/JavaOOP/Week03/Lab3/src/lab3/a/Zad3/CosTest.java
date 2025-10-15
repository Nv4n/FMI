package lab3.a.Zad3;

import java.util.Scanner;

public class CosTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter x: ");
        double x = input.nextDouble();
        System.out.print("Enter epsilon's precision: ");
        double e = input.nextDouble();

        CalculateCos calcCos = new CalculateCos(x, e);

        System.out.printf("Math class results:x:\t%f%ncos(%f):\t%f%n%n",
                calcCos.getX(), calcCos.getX(), Math.cos(calcCos.getX()));

        System.out.printf("CalculateCos class results:x:\t%f%ncos(%f):\t%f%n%n",
                calcCos.getX(), calcCos.getX(), calcCos.getCos());

    }
}
