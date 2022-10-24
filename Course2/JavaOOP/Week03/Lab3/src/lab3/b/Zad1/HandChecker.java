package lab3.b.Zad1;

public class HandChecker {
    private static final String[] FACES = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    private static final String[] SUITS = {"Hearts", "Diamonds", "Clubs", "Spades"};
    private static int[] facesCount = new int[13];

    // FIXME: 10/21/2022
    //  Simplify the methods
    //  Check if you have pair && !2pairs
    //  Check if you have full house instead of pair && tierce
    public static boolean hasPair() {
        return hasNCount(2) && !has2Pairs() && !hasTierce();
    }

    public static boolean has2Pairs() {
        int count = 0;
        for (int i : facesCount)
            if (i == 2)
                count++;
        return count == 2;
    }

    public static boolean hasTierce() {
        return hasNCount(3);
    }

    public static boolean hasQuarter() {
        return hasNCount(4);
    }

    public static boolean hasQuint(Card[] hand) {
        for (int i = 1; i < hand.length; i++) {
            if (!hand[i].getSuit().equals(hand[i - 1].getSuit()))
                return false;
        }
        return true;
    }

    public static boolean hasSequence(Card[] hand) {
        int count = 0;
        for (int i = 1; i < facesCount.length; i++) {
            if (facesCount[i] == 1)
                count++;
            else if (count == 5)
                break;
            else
                count = 0;
        }
        return count == 5;
    }

    public static boolean hasFullHouse(Card[] hand) {
        return hasPair(hand) && hasTierce(hand);
    }

    public static void initsHand(Card[] hand) {

        if (hand.length != 5)
            throw new IllegalArgumentException("Length must be 5: " + hand.length);

        totalHandFaces(hand);
    }

    private static boolean hasNCount(int count) {
        for (int i : facesCount) {
            if (i == count)
                return true;
        }
        return false;
    }

    private static void totalHandFaces(Card[] hand) {
        for (Card card : hand) {
            for (int i = 0; i < facesCount.length; i++)
                if (card.getFace().equals(FACES[i])) {
                    facesCount[i]++;
                    break;
                }
        }
    }
}
