package lab2b.Zad1;

public class Table {
    private double start;
    private double end;
    private int steps;

    public Table(double start, double end, int steps) {
        setStart(Math.max(start, end));
        setEnd(Math.min(start, end));
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

    }
}
