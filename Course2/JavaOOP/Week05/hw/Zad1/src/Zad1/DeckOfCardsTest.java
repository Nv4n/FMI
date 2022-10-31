// Fig. 7.11: DeckOfCardsTest.java
// Card shuffling and dealing application.
package Zad1;

public class DeckOfCardsTest {
    // execute application
    public static void main(String[] args) {
        DeckOfCards myDeckOfCards = new DeckOfCards();
        myDeckOfCards.shuffle(); // place Cards in random order

        CouponCollector.getPickCounts(myDeckOfCards);
    } // end main
} // end class DeckOfCardsTest