package Zad1;

import java.util.Arrays;

public class Point {
    private int[] coordinates;

    public Point() {
        this(new int[]{0, 0});
    }

    public Point(int[] coordinates) {
        setCoordinates(coordinates);
    }

    public Point(Point other) {
        this(other.getCoordinates());
    }

    public int[] getCoordinates() {
        return new int[]{coordinates[0], coordinates[1]};
    }

    public void setCoordinates(int[] coordinates) {
        if (coordinates != null && coordinates.length == 2)
            this.coordinates = new int[]{Math.abs(coordinates[0]), Math.abs(coordinates[1])};
        else
            this.coordinates = new int[]{0, 0};
    }

    @Override
    public String nodeToString() {
        return String.format("X:%d\tY:%d",
                coordinates[0],
                coordinates[1]);
    }
}
