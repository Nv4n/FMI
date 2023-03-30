package Zad1a;

public class HandChecker {
    private final String[] faces;
    private final String[] suits;
    private Card[] hand;
    private int[] currentFaces;
    private int[] currentSuits;

    HandChecker(Card[] hand) {
        faces = new String[]{"Ace", "Deuce", "Three", "Four", "Five", "Six",
                "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        suits = new String[]{"Hearts", "Diamonds", "Clubs", "Spades"};
        setHand(hand);
    }

    public void setHand(Card[] hand) {
        this.hand = hand != null ? hand : new Card[0];
        currentFaces = new int[faces.length];
        currentSuits = new int[suits.length];

        for (Card card : this.hand) {
            String face = card.getFace();
            for (int j = 0; j < faces.length; j++)
                if (faces[j].equals(face)) {
                    currentFaces[j]++;
                    break;
                }

            String suit = card.getSuit();
            for (int j = 0; j < suits.length; j++)
                if (suits[j].equals(suit)) {
                    currentSuits[j]++;
                    break;
                }
        }
    }

    public boolean hasPair() {
        int pairCount = 0;
        for (int currentFace : currentFaces) {
            if (currentFace == 2) pairCount++;
            if (pairCount > 1) return false;
        }
        return pairCount == 1;
    }

    public boolean hasTwoPairs() {
        int pairCount = 0;
        for (int currentFace : currentFaces) {
            if (currentFace == 2) pairCount++;
            if (pairCount == 2) break;
        }
        return pairCount == 2;
    }

    public boolean hasThreeKind() {
        for (int currentFace : currentFaces)
            if (currentFace == 3) return true;
        return false;
    }

    public boolean hasFourKind() {
        for (int currentFace : currentFaces)
            if (currentFace == 4) return true;
        return false;
    }

    public boolean hasFlush() {
        for (int currentSuit : currentSuits)
            if (currentSuit == 5) return true;
        return false;
    }

    public boolean hasStraight() {
        for (int i = 0; i < currentFaces.length - 4; i++)
            if (currentFaces[i] == 1
                    && currentFaces[i + 1] == 1
                    && currentFaces[i + 2] == 1
                    && currentFaces[i + 3] == 1
                    && currentFaces[i + 4] == 1) return true;
        return false;
    }

    public boolean hasFullHouse() {
        return hasPair() && hasThreeKind();
    }

}
