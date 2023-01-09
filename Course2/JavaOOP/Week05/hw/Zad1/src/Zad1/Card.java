package Zad1;
// Fig. 7.9: Card.java
// Card class represents a playing card.

public class Card {
    private final String face; // face of card ("Ace", "Deuce", ...)
    private final String suit; // suit of card ("Hearts", "Diamonds", ...)

    // two-argument constructor initializes card's face and suit
    public Card(String cardFace, String cardSuit) {
        face = new String(cardFace); // initialize face of card
        suit = new String(cardSuit); // initialize suit of card
    } // end two-argument Card constructor

    public Card(Card c) {
        this(c.getFace(), c.getSuit());
    }

    public String getFace() {
        return new String(face);
    }

    public String getSuit() {
        return new String(suit);
    }

    // return String representation of Card
    public String toString() {
        return face + " of " + suit;
    } // end method nodeToString
} // end class Card
