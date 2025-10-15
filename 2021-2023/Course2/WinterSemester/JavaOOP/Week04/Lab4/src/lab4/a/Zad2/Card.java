package lab4.a.Zad2;

public class Card {
    private long cardNumber;

    public Card(long cardNumber) {
        setCardNumber(cardNumber);
    }

    public long getCardNumber() {
        return cardNumber;
    }

    public void setCardNumber(long cardNumber) {
        if (cardNumber < 0)
            throw new IllegalArgumentException("Card number can't be negative number!");
        int size = Long.nodeToString(cardNumber).length();
        if (size < 13 || size > 16)
            throw new IllegalArgumentException("Invalid card number length!");

        this.cardNumber = cardNumber;
    }
}
