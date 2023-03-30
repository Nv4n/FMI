// Lab 1: Shapes.java
// Program draws four shapes to the command window.
package labexercises.lab1;


public class Shapes {

    public static void main(String args[]) {
      /* write a series of statements that will print the shapes
         to the command window */
        printRectangle(5, 6);
        System.out.println();
        printSquare(5);
        System.out.println();
        printRomb(10);
    }

    private static void printRectangle(int width, int height) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i > 0 && i < height - 1) {
                    if (j > 0 && j < width - 1) {
                        System.out.print(" ");
                    } else {
                        System.out.print("*");
                    }
                } else {
                    System.out.print("*");
                }
            }
            System.out.println();
        }
    }

    private static void printSquare(int width) {
        printRectangle(width, width);
    }

    private static void printRomb(int diagonal) {
        for (int i = 0; i < diagonal / 2; i++) {
            for (int j = 0; j <= diagonal / 2 - i; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j <= i * 2; j++) {
                System.out.print("*");
            }
            System.out.println();
        }

        for (int i = diagonal / 2; i >= 0; --i) {
            for (int j = 0; j <= diagonal / 2 - i; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j <= i * 2; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
} // end class Shapes

 