// Fig. 7.10: DeckOfCards.java
// DeckOfCards class represents a deck of playing cards.
package lab3.b.Zad1;

import java.util.Random;

public class DeckOfCards {
    private final Card[] deck; // array of Card objects
    private int currentCard; // index of next Card to be dealt
    private final int NUMBER_OF_CARDS = 52; // constant number of Cards
    private final Random randomNumbers; // random number generator

    private final String[] faces = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    private final String[] suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // constructor fills deck of Cards
    public DeckOfCards() {
        deck = new Card[NUMBER_OF_CARDS]; // create array of Card objects
        currentCard = 0; // set currentCard so first Card dealt is deck[ 0 ]
        randomNumbers = new Random(); // create random number generator

        // populate deck with Card objects
        for (int count = 0; count < deck.length; count++)
            deck[count] =
                    new Card(faces[count % 13], suits[count / 13]);
    } // end DeckOfCards constructor

    // shuffle deck of Cards with one-pass algorithm
    public void shuffle() {
        // after shuffling, dealing should start at deck[ 0 ] again
        currentCard = 0; // reinitialize currentCard

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
        // determine whether Cards remain to be dealt
        if (currentCard < deck.length)
            return deck[currentCard++]; // return current Card in array
        else
            return null; // return null to indicate that all Cards were dealt
    } // end method dealCard

    public Card[] deal5Cards() {
        Card[] hand = new Card[5];
        for (int i = 0; i < hand.length; i++) {
            hand[i] = dealCard();
        }
        return hand;
    }

    public boolean hasPair(Card[] hand) {
        int[] handCount = getInts(hand);
        return hasNCount(handCount, 2);
    }

    public boolean has2Pairs(Card[] hand) {
        int[] handCount = getInts(hand);
        int count = 0;
        for (int i : handCount)
            if (i == 2)
                count++;
        return count == 2;
    }

    public boolean hasTierce(Card[] hand) {
        int[] handCount = getInts(hand);
        return hasNCount(handCount, 3);
    }

    public boolean hasQuarter(Card[] hand) {
        int[] handCount = getInts(hand);
        return hasNCount(handCount, 4);
    }

    public boolean hasQuint(Card[] hand) {
        for (int i = 1; i < hand.length; i++) {
            if (!hand[i].getSuit().equals(hand[i - 1].getSuit()))
                return false;
        }
        return true;
    }

    public boolean hasSequence(Card[] hand) {
        int[] handCount = getInts(hand);
        for (int i = 1; i < handCount.length; i++) {
            if (handCount[i] == 0 && handCount[i - 1] >= 1
                    || handCount[i] > 1)
                return false;
        }
        return true;
    }

    public boolean hasFullHouse(Card[] hand) {
        boolean meetsCondition = false;
        int[] handCount = new int[4];
        for (int i = 0; i < handCount.length; i++) {
            for (Card card : hand) {
                if (card.getSuit().equals(suits[i]))
                    handCount[i]++;
            }
        }

        for (int i : handCount) {
            meetsCondition = meetsCondition || i == 3;
        }
        for (int i : handCount) {
            meetsCondition = meetsCondition && i == 2;
        }

        return meetsCondition;
    }

    private int[] totalHandFaces(Card[] hand) {
        int[] countHand = new int[13];
        for (int i = 0; i < countHand.length; i++) {
            for (Card card : hand) {
                if (card.getFace().equals(faces[i]))
                    countHand[i]++;
            }
        }
        return countHand;
    }

    private static boolean hasNCount(int[] handCount, int count) {
        for (int i : handCount) {
            if (i == count)
                return true;
        }
        return false;
    }

    private int[] getInts(Card[] hand) {
        if (hand.length != 5)
            throw new IllegalArgumentException("Length must be 5: " + hand.length);

        return totalHandFaces(hand);
    }
} // end class DeckOfCards


/**************************************************************************
 * (C) Copyright 1992-2005 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
