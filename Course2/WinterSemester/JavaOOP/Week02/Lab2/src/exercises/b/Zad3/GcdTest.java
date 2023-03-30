package exercises.b.Zad3;

import java.util.Scanner;

public class GcdTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int number1 = input.nextInt();
        System.out.print("Enter second number: ");
        int number2 = input.nextInt();
        Gcd gcd = new Gcd(number1, number2);
        printGCD(gcd);
        
        System.out.print("Enter third number: ");
        int number3 = input.nextInt();
        gcd.setNumber2(number3);
        printGCD(gcd);
    }

    private static void printGCD(Gcd gcd) {
        System.out.printf("""
                        First number: %d\tSecond number: %d
                        Their GCD is: %d%n
                        """ ,
                gcd.getNumber1(), gcd.getNumber2(), gcd.getGcdNumber());
    }
}
