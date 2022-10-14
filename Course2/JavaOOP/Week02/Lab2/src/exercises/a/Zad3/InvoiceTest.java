package exercises.a.Zad3;

import java.util.Scanner;

public class InvoiceTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter part number: ");
        String partNumber = input.next();

        System.out.print("Enter part description: ");
        String partDescription = input.next();

        System.out.print("Enter part quantity: ");
        int quantity = input.nextInt();

        System.out.print("Enter part price: ");
        double price = input.nextDouble();

        Invoice invoice1 = new Invoice(partNumber, partDescription, quantity, price);

        displayInvoiceInfo(invoice1);

        invoice1.setPrice(15);
        invoice1.setQuantity(10);

        displayInvoiceInfo(invoice1);
    }

    private static void displayInvoiceInfo(Invoice invoice1) {
        //Display results
        System.out.printf("""
                        Part: #%s\tInfo: %s
                        Quantity:%d
                        Price:%,.2f
                        _______
                        Total:%,.2f
                        """,
                invoice1.getPartNumber(), invoice1.getPartDescription(),
                invoice1.getQuantity(), invoice1.getPrice(),
                invoice1.getInvoiceAmount()
        );
    }
}
