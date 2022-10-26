package lab3.b.Zad1;

import java.util.Arrays;

public class HandChecker {
    private static final String[] FACES = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    private static final String[] SUITS = {"Hearts", "Diamonds", "Clubs", "Spades"};
    private static int[] facesCount = new int[13];


    public static boolean hasPair() {
        return !has2Pairs() && hasNCount(2) && !hasNCount(3);
    }

    public static boolean has2Pairs() {
        int count = 0;
        for (int i : facesCount)
            if (i == 2)
                count++;
        return count == 2;
    }

    public static boolean hasTierce() {
        return hasNCount(3) && !hasNCount(2);
    }

    public static boolean hasQuarter() {
        return hasNCount(4);
    }

    public static boolean hasSameSuit(Card[] hand) {
        String suit = hand[0].getSuit();
        for (int i = 1; i < hand.length; i++) {
            if (!hand[i].getSuit().equals(suit))
                return false;
        }
        return true;
    }

    public static boolean hasSequence() {
        int count = 0;
        for (int i : facesCount)
            if (i == 1)
                count++;
            else if (count == 5)
                break;
            else if (count > 0)
                break;
        return count == 5;
    }

    public static boolean hasFullHouse() {
        return hasPair() && hasTierce();
    }

    public static void initsHand(Card[] hand) {
        if (hand.length != 5)
            throw new IllegalArgumentException("Length must be 5: " + hand.length);

        Arrays.fill(facesCount, 0);
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
