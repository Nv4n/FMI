package Zad1;

public class GeometryTest {
    public static void main(String[] args) {
        Point a = new Point();
        Point b = new Point(new int[]{4, 2});
        Point c = new Point(b);
        c.setCoordinates(new int[]{4, 5});
        System.out.println("POINT");
        System.out.printf("%s\t%s\t%s%n", a, b, c);
        System.out.println("LINE");
        Line lineA = new Line(a, c);
        System.out.printf("%s\t%.2f%n", lineA, lineA.measure());
        System.out.println("RECT");
        Rectangle rect = new Rectangle(a, b);
        System.out.printf("%s\t%.2f", rect, rect.measure());
    }
}
