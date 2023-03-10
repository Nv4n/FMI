package com.problem2;

import java.io.IOException;
import java.util.Scanner;

public class ComputeByMenu {
    private final Scanner INPUT;
    private double x;

    public ComputeByMenu(double x) {
        INPUT = new Scanner(System.in);
        this.x = x;
    }

    public void getUserChoice() {
        displayMenu();
        System.out.print("Enter your choice: ");
        int choice = INPUT.nextInt();
        doSelection(choice);
    }

    public void displayMenu() {
        System.out.println("\n".repeat(50));
        System.out.print("""
                1. Update the floating point number
                2. Compute and display exp(x)
                3. Compute and display sin(x)
                4. Compute and display floor(x)
                5. Exit
                """);
    }

    public void doSelection(int choice) {
        switch (choice) {
            case 1 -> updateX();
            case 2 -> System.out.printf("exp(%f) = %f%n", x, Math.exp(x));
            case 3 -> System.out.printf("sin(%f) = %f%n", x, Math.sin(x));
            case 4 -> System.out.printf("floor(%f) = %f%n", x, Math.floor(x));
            case 5 -> System.exit(0);
            default -> {
                System.out.println("Invalid choice");
            }
        }
        System.out.print("Press enter to continue...");
        try {
            System.in.read();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        getUserChoice();
    }

    private void updateX() {
        System.out.print("Enter new value for x: ");
        this.x = INPUT.nextDouble();
    }
}
