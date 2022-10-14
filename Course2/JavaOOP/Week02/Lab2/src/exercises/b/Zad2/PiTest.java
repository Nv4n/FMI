package exercises.b.Zad2;

public class PiTest {
    public static void main(String[] args) {
        Pi pi = new Pi();
        while (!String.format("%.4f", pi.getPi()).equals("3.1415")) {
            printCurrentPi(pi);
            pi.nextPi();
        }
        printCurrentPi(pi);
    }

    private static void printCurrentPi(Pi pi) {
        System.out.printf("N: %d\tpi: %.4f%n", pi.getIndex(), pi.getPi());
    }
}
