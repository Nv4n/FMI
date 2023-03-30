package lab3.a.Zad1;

import java.util.Scanner;

public class ComputeByMenu {
    private double x;
    private final Scanner input = new Scanner(System.in);

    public ComputeByMenu() {
        this(0.00);
    }

    public ComputeByMenu(double x) {
        this.x = x;
    }

    public double getX() {
        return x;
    }

    // private void displayMenu() should be more appropriate
    // as we call displayMenu() only in getUserChoice()
    private void displayMenu() {
        System.out.print("%n".repeat(50));

        System.out.println("""
                1. Въведи число x в плаваща запетая
                2. Пресметни и изведи exp(x)
                3. Пресметни и изведи sin(x)
                4. Пресметни и изведи floor(x)
                5. Край\
                """);
    }

    public void doSelection(int choice) {
        switch (choice) {
            case 1 -> {
                Scanner input = new Scanner(System.in);
                System.out.print("Enter x: ");
                x = input.nextDouble();
            }
            case 2 -> System.out.printf("exp(%.2f):\t%.4f%n", x, Math.exp(x));
            case 3 -> System.out.printf("sin(%.2f):\t%.4f%n", x, Math.sin(x));
            case 4 -> System.out.printf("floor(%.2f):\t%.2f%n", x, Math.floor(x));
            case 5 -> {
                return;
            }
            default -> System.out.println("Choice doesn't exist");
        }
        System.out.print("Press return to continue...");
        input.nextLine();
        if (input.hasNextLine())
            getUserChoice();
    }

    public void getUserChoice() {
        displayMenu();
        int choice = input.nextInt();
        doSelection(choice);
    }
}
