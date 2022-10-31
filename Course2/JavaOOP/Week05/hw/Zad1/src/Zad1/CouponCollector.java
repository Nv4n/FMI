package Zad1;

public class CouponCollector {
    public static void getPickCounts(DeckOfCards deck) {
        countPicks(1, deck);
    }

    private static void countPicks(int picksCount, DeckOfCards deck) {
        Card[] hand = new Card[4];
        for (int hi = 0; hi < hand.length; hi++)
            hand[hi] = deck.dealCard();

        for (int crrHndInd = 0; crrHndInd < hand.length - 1; crrHndInd++) {
            String suit = hand[crrHndInd].getSuit();
            for (int hi = crrHndInd + 1; hi < hand.length; hi++)
                if (suit.equals(hand[hi].getSuit())) {
                    countPicks(++picksCount, deck);
                    return;
                }
        }
        for (Card c : hand)
            System.out.println(c.toString());
        System.out.printf("Number of picks: %d", picksCount);
    }
}
