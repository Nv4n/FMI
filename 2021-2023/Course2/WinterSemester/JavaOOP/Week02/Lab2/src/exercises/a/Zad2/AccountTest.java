// Fig. 3.14: AccountTest.java
// Create and manipulate an Account object.
package exercises.a.Zad2;

import java.util.Scanner;

public class AccountTest {
    public static void main(String[] args) {
        Account acc1 = new Account(50);
        Account acc2 = new Account(-7.53);
        System.out.printf("Account 1 balance: $%.2f%n",
                acc1.getBalance());
        System.out.printf("Account 2 balance: $%.2f%n",
                acc2.getBalance());

        Scanner input = new Scanner(System.in);
        //Adding balance to account1
        System.out.print("Enter deposit amount for account1: ");
        double depositAmount = input.nextDouble();

        System.out.printf("%nadding %.2f to account1 balance%n%n",
                depositAmount);
        acc1.credit(depositAmount);

        //display balances
        System.out.printf("Account 1 balance: $%.2f%n",
                acc1.getBalance());
        System.out.printf("Account 2 balance: $%.2f%n",
                acc2.getBalance());

        //Adding to account2 balance
        System.out.print("Enter deposit amount for account2: ");
        depositAmount = input.nextDouble();

        System.out.printf("%nadding %.2f to account2 balance%n%n",
                depositAmount);
        acc2.credit(depositAmount);

        //display balances
        System.out.printf("Account 1 balance: $%.2f%n",
                acc1.getBalance());
        System.out.printf("Account 2 balance: $%.2f%n",
                acc2.getBalance());

        //test debit
        System.out.print("Enter debit amount for account2: ");
        double debitAmount = input.nextDouble();

        System.out.printf("%nwithdrawing %.2f from account2 balance%n%n",
                debitAmount);
        acc2.debit(debitAmount);

        //display balances
        System.out.printf("Account 1 balance: $%.2f%n",
                acc1.getBalance());
        System.out.printf("Account 2 balance: $%.2f%n",
                acc2.getBalance());
    }
}
