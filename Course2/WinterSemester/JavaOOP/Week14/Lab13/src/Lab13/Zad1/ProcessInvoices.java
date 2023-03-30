package Lab13.Zad1;
// Processing Invoices with lambdas and streams.

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;

public class ProcessInvoices {

    public static void main(String[] args) {
        Invoice[] invoices = {
                new Invoice(83, "Electric sander", 7, 57.98),
                new Invoice(24, "Power saw", 18, 99.99),
                new Invoice(7, "Sledge hammer", 11, 21.50),
                new Invoice(77, "Hammer", 76, 11.99),
                new Invoice(39, "Lawn mower", 3, 79.50),
                new Invoice(68, "Screwdriver", 106, 6.99),
                new Invoice(56, "Jig saw", 21, 11.00),
                new Invoice(3, "Wrench", 34, 7.50)
        };

        System.out.println("Invoices sorted by part description:");
        Arrays.stream(invoices)
                .sorted(Comparator.comparing(Invoice::getPartDescription))
                .forEach(System.out::println);

        System.out.println();
        System.out.printf("Invoices sorted by price:%n");
        Arrays.stream(invoices)
                .sorted(Comparator.comparing(Invoice::getPrice))
                .forEach(System.out::println);

        System.out.println();
        System.out.printf("%nInvoices mapped to description and quantity:%n");
        Arrays.stream(invoices)
                .sorted(Comparator.comparing(Invoice::getQuantity))
                .map(invoice -> String.format(
                        "Description: %-15s  Quantity: %d",
                        invoice.getPartDescription(), invoice.getQuantity()))
                .forEach(System.out::println);

        System.out.println();
        System.out.printf("%nInvoices mapped to description and invoice amount:%n");
        Arrays.stream(invoices)
                .sorted(Comparator.comparingDouble(invoice -> invoice.getQuantity() * invoice.getPrice()))
                .map(invoice -> String.format(
                        "Description: %-15s  Invoice amount: %7.2f",
                        invoice.getPartDescription(), invoice.getQuantity() * invoice.getPrice()))
                .forEach(System.out::println);

        System.out.println();
        System.out.printf("%nInvoices mapped to description and invoice amount for invoices in the range 200-500:%n");
        Arrays.stream(invoices)
                .filter(invoice -> invoice.getQuantity() * invoice.getPrice() >= 200 && invoice.getQuantity() * invoice.getPrice() <= 500)
                .sorted(Comparator.comparingDouble(invoice -> invoice.getQuantity() * invoice.getPrice()))
                .map(invoice -> String.format(
                        "Description: %-15s  Invoice amount: %7.2f",
                        invoice.getPartDescription(), invoice.getQuantity() * invoice.getPrice()))
                .forEach(System.out::println);

        System.out.println();
        System.out.printf("%nInvoices grouped below and above $300 invloce value:%n");
        Arrays.stream(invoices)
                .filter(invoice -> invoice.getQuantity() * invoice.getPrice() >= 200 && invoice.getQuantity() * invoice.getPrice() <= 500)
                .sorted(Comparator.comparingDouble(invoice -> invoice.getQuantity() * invoice.getPrice()))
                .map(invoice -> String.format(
                        "Description: %-15s  Invoice amount: %7.2f",
                        invoice.getPartDescription(), invoice.getQuantity() * invoice.getPrice()))
                .forEach(System.out::println);
        Map<String, List<Invoice>> groupedByInvoiceValue
                = Arrays.stream(invoices)
                .collect(Collectors.groupingBy(x -> x.getValue() <= 300 ? "Below 300" : "Above 300"));

        groupedByInvoiceValue.forEach(
                (keyTitle, invoiceList)
                        -> {
                    System.out.println(keyTitle);
                    invoiceList.forEach(
                            invoice -> System.out.printf("   %s%n", invoice));
                }
        );

        Optional<Integer> max = Arrays.stream(invoices).map(Invoice::getQuantity).reduce(Math::max);
        max.ifPresent(System.out::println);
        Optional<Invoice> maxi = Arrays.stream(invoices).max(Comparator.comparingInt(Invoice::getQuantity));
        maxi.ifPresent(System.out::println);
    }
}