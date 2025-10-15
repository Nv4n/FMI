package payment;

import com.Payable;

import java.rmi.AccessException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.text.NumberFormat;
import java.util.logging.Level;
import java.util.logging.Logger;

public class PaymentApp {

    public static void main(String[] args) {
        try {
            Registry r = LocateRegistry.getRegistry("localhost", 1099);
            Payable payment = null;
            try {
                payment = (Payable) r.lookup("Payment");
            } catch (NotBoundException | AccessException ex) {
                Logger.getLogger(PaymentApp.class.getName()).log(Level.SEVERE, null, ex);
            }
            NumberFormat percentFormat = NumberFormat.getPercentInstance();
            NumberFormat currencyFormat = NumberFormat.getCurrencyInstance();

            double paymentAmount = payment != null ? payment.monthlyPayment(0.05, 1000.) : 0;
            System.out.printf("Rate: %s, Amount: %s, Monthly payment: %s%n",
                    percentFormat.format(0.05),
                    currencyFormat.format(1000.0),
                    currencyFormat.format(paymentAmount));
            paymentAmount = payment != null ? payment.totalPayment(0.05, 1000., 5) : 0;
            System.out.printf("Total payment at the end of the year: %s%n",
                    currencyFormat.format(paymentAmount));
        } catch (RemoteException ex) {
            Logger.getLogger(PaymentApp.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
