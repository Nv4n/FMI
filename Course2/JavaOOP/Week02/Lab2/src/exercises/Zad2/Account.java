// Fig. 3.13: Account.java
// Account class with a constructor to
// initialize instance variable balance.
package exercises.Zad2;

public class Account {
    private double balance;

    public Account(double initialBalance) {
        setBalance(initialBalance);
    }

    public double getBalance() {
        return balance;
    }

    private void setBalance(double balance) {
        if (balance > 0)
            this.balance = balance;
    }

    //credit(add) an amount to balance
    public void credit(double amount) {
        //validate amount is positive
        balance += (amount > 0) ? amount : 0;
    }

    public void debit(double amount) {
        //validate amount is positive and not greater than balance
        if (amount >= 0 && amount <= balance)
            balance -= amount;
        else
            System.out.println("Debit amount exceeded account balance.");
    }
}//end class Account

