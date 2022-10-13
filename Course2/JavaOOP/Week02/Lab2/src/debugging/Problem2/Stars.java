package debugging.Problem2;// Stars.java
// Program prints a checkerboard pattern.
// Correct the syntax error

public class Stars {

    // main method begins execution of program
    public static void main(String[] args) {
        //While loops -> For loops
        //Stars -> Black/White squares
        for (int row = 1; row <= 8; row++) {
            for (int column = 0; column <= 8; column++) {
                if ((row % 2 == 0) == (column % 2 != 0))
                    System.out.print("\u2B1C"); //Big white square
                else
                    System.out.print("\u2B1B"); //Big black square
            }//end 2nd for loop
            System.out.println();
        }//end 1st for loop
    }  // end method main
}  // end class Stars
