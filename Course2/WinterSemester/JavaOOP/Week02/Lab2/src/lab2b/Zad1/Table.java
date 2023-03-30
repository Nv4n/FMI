package lab2b.Zad1;

import java.util.Scanner;

public class Table {
    private double start;
    private double end;
    private int steps;

    public Table(double start, double end, int steps) {
        setStart(Math.min(start, end));
        setEnd(Math.max(start, end));
        setSteps(steps);
    }

    public double getStart() {
        return start;
    }

    public void setStart(double start) {
        this.start = start;
    }

    public double getEnd() {
        return end;
    }

    public void setEnd(double end) {
        this.end = end;
    }

    public int getSteps() {
        return steps;
    }

    public void setSteps(int steps) {
        this.steps = steps > 0 ? steps : 1;
    }

    public void makeTable() {
        double interval = (end - start) / steps;
        double x = start;
        Scanner input = new Scanner(System.in);

        for (int i = 1; i <= steps; i++) {
            System.out.printf("x is %.4f\tf(x) is %.4f%n",
                    x, (x - 2) * (x - 2) / (x * x + 1));

            if (i % 20 == 0) {
                System.out.print("Press return to continue ...");
                input.nextLine();
            }

            x += interval;
        }
    }
}
