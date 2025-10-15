package app;


import module.Circle;
import module.Cylinder;
import module.Point;

import java.util.Random;

public class SelectionSortTest {
    public static void main(String[] args) {
        Random rand = new Random();
        Comparable[] arrComparable = new Comparable[9];
        int arrI = 0;

        for (int i = 0; i < 3 && arrI < arrComparable.length; i++, arrI++) {
            int x = rand.nextInt(10, 50) + 1;
            int y = rand.nextInt(10, 50) + 1;
            arrComparable[arrI] = new Point(x, y);
        }

        for (int i = 0; i < 3 && arrI < arrComparable.length; i++, arrI++) {
            Point p = (Point) arrComparable[i];
            int radius = rand.nextInt(10, 30) + 1;
            arrComparable[arrI] = new Circle(p.getX(), p.getY(), radius);
        }

        for (int i = 0, circleI = 3; i < 3 && arrI < arrComparable.length; i++, arrI++, circleI++) {
            Circle c = (Circle) arrComparable[circleI];
            int height = rand.nextInt(10, 60) + 1;
            arrComparable[arrI] = new Cylinder(c.getX(), c.getY(), c.getRadius(), height);
        }

        SelectionSort.sortArray(arrComparable);
        for (Comparable obj : arrComparable) System.out.println(obj.toString());
    }
}
