// Fig. 7.10: DeckOfCards.java
// DeckOfCards class represents a deck of playing cards.
package Zad1;

import java.util.Random;

public class DeckOfCards {
    private final Card[] deck; // array of Card objects
    private final int NUMBER_OF_CARDS = 52; // constant number of Cards
    @SuppressWarnings("FieldMayBeFinal")
    private Random randomNumbers; // random number generator


    // constructor fills deck of Cards

    public DeckOfCards() {
        String[] faces = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
                "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        String[] suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

        deck = new Card[NUMBER_OF_CARDS]; // create array of Card objects
        randomNumbers = new Random(); // create random number generator

        // populate deck with Card objects
        for (int count = 0; count < deck.length; count++)
            deck[count] =
                    new Card(faces[count % 13], suits[count / 13]);
    } // end DeckOfCards constructor
    // shuffle deck of Cards with one-pass algorithm

    public void shuffle() {
        // after shuffling, dealing should start at deck[ 0 ] again

        // for each Card, pick another random Card and swap them
        for (int first = 0; first < deck.length; first++) {
            // select a random number between 0 and 51
            int second = randomNumbers.nextInt(NUMBER_OF_CARDS);

            // swap current Card with randomly selected Card
            Card temp = deck[first];
            deck[first] = deck[second];
            deck[second] = temp;
        } // end for
    } // end method shuffle

    // deal one Card
    public Card dealCard() {
        int i = randomNumbers.nextInt(deck.length);
        return new Card(deck[i]);
    } // end method dealCard
} // end class DeckOfCards