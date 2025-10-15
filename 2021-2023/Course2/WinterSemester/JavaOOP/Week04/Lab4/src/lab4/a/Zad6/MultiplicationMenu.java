package lab4.a.Zad6;

import java.util.Random;
import java.util.Scanner;

public class MultiplicationMenu {
    private int firstMultiplier;
    private int secondMultiplier;
    private Random randomNumber;
    private Scanner input;

    public MultiplicationMenu() {
        randomNumber = new Random();
        input = new Scanner(System.in);
        firstMultiplier = 0;
        secondMultiplier = 0;
    }

    public void showMenu() {
        firstMultiplier = getMultiplier();
        secondMultiplier = getMultiplier();

        System.out.printf("""
                        You can always exit with answering 0
                        How much is %1$d times %2$d?\t\
                        """,
                firstMultiplier,
                secondMultiplier);

        getUserInput();
    }

    private void getUserInput() {
        int answer = input.nextInt();
        checkUserInput(answer);
    }

    private void checkUserInput(int answer) {
        if (answer == 0) {
            System.out.println("Thank you for learning with us!");
            return;
        }

        if (answer == firstMultiplier * secondMultiplier) {
            System.out.println("Very good!");
            showMenu();
        } else {
            System.out.println("No. Please try again.");
            getUserInput();
        }
    }

    private int getMultiplier() {
        return randomNumber.nextInt(9) + 1;
    }
}
