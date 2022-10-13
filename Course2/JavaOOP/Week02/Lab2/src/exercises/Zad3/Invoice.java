package exercises.Zad3;

public class Invoice {
    private String partNumber;
    private String partDescription;
    private int quantity;
    private double price;

    public Invoice(String partNumber, String partDescription, int quantity, double price) {
        setPartNumber(partNumber);
        setPartDescription(partDescription);
        setQuantity(quantity);
        setPrice(price);
    }

    public String getPartNumber() {
        return partNumber;
    }

    //Part number and part description
    //shouldn't be changeable after initialization
    private void setPartNumber(String partNumber) {
        this.partNumber = partNumber != null ? partNumber : "Default part number";
    }

    public String getPartDescription() {
        return partDescription;
    }

    private void setPartDescription(String partDescription) {
        this.partDescription = partDescription != null ? partDescription : "Default description";
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity > 0 ? quantity : 0;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price > 0 ? price : 0;
    }

    public double getInvoiceAmount() {
        return price * quantity;
    }
}
