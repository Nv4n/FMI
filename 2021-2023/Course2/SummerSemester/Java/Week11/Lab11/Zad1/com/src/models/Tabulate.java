package models;

import implementable.Computable;

import java.util.Scanner;

public class Tabulate {
    private Computable callback;

    public Tabulate(Computable callback) {
        setCallback(callback);
    }

    public Computable getCallback() {
        return callback;
    }

    public void setCallback(Computable callback) {
        this.callback = callback;
    }

    public void tabulate(double a, double b, int steps) {
        tabulateFunction(a, b, steps, callback);
    }

    public static void tabulateFunction(double a, double b,
                                        int steps, Computable computable) {
        if (steps < 1) {
            System.out.println("Invalid steps!");
            return;
        }


        Scanner waiter = new Scanner(System.in);
        double offset = Math.abs(a - b) / steps;
        double x = a;
        System.out.printf("%10s\t%10s\n", "x", "F(x)");
        x = a;
        for (int i = 0; i <= steps; i++, x += offset) {
            if (i != 0 && i % 20 == 0) {
                System.out.println("Please enter to continue...");
                waiter.nextLine();
                System.out.printf("%10s\t%10s\n", "x", "F(x)");
            }
            double fx = computable.function(x);
            System.out.printf("%10.2f\t%10.2f\n", x, fx);
        }
    }
}
