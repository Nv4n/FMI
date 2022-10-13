package debugging.Problem1;// Table.java
// Program prints a table of values [1,2, 3 ,4 5] using a while loop.
// Correct the syntax errors and execute the program!

public class Table {

    // main method begins execution of Java application
    public static void main(String[] args) {
        int n = 1;

        System.out.print("N│\t10*N│\t100*N│\t1000*N\n");

        while (n <= 5) {
            System.out.printf("%d│\t%4d│\t%5d│\t%6d\n",
                    n, n * 10, n * 100, n * 1000);
            n++;
        }
    }

} // end class Table
