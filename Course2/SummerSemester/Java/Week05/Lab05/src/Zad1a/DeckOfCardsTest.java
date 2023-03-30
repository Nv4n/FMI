package Zad1a;// Fig. 7.11: DeckOfCardsTest.java
// Card shuffling and dealing application.

import java.util.Arrays;

public class DeckOfCardsTest {
    // execute application
    public static void main(String[] args) {
        DeckOfCards myDeckOfCards = new DeckOfCards();
        myDeckOfCards.shuffle(); // place Cards in random order

        // print all 52 Cards in the order in which they are dealt
//      for ( int i = 0; i < 13; i++ )
//      {
//         // deal and print 4 Cards
//         System.out.printf( "%-20s%-20s%-20s%-20s\n",
//            myDeckOfCards.dealCard(), myDeckOfCards.dealCard(),
//            myDeckOfCards.dealCard(), myDeckOfCards.dealCard() );
//      } // end for

        Card[] player1Hand = myDeckOfCards.dealHand();
        Card[] player2Hand = myDeckOfCards.dealHand();
        System.out.printf("%-20s\t%-20s%n", "Left hand:", "Right hand:");
        for (int i = 0; i < player1Hand.length; i++) {
            System.out.printf("%-20s\t%-20s%n", player1Hand[i], player2Hand[i]);
        }
//        System.out.printf("Left hand: %s%n", Arrays.toString(player1Hand));
//        System.out.printf("Right hand %s%n", Arrays.toString(player2Hand));
        HandChecker leftChecker = new HandChecker(player1Hand);
        HandChecker rightChecker = new HandChecker(player2Hand);

        System.out.println("Hand values:");
        int leftPower = checkHand(leftChecker);
        int rightPower = checkHand(rightChecker);
        System.out.println();
        System.out.print("Result: ");
        if (leftPower > rightPower) System.out.println("left hand is better");
        else if (leftPower < rightPower) System.out.println("right hand is better");
        else System.out.println("tie");


        boolean hasFours = false;
        int deals = 0;
        do {
            DeckOfCards newDeck = new DeckOfCards();
            hasFours = new HandChecker(newDeck.dealHand()).hasFourKind();
            deals++;
        } while (!hasFours);


        System.out.println(deals);
    } // end main

    private static int checkHand(HandChecker checker) {
        if (checker.hasFullHouse()) {
            System.out.printf("%-20s\t", "Full house");
            return 6;
        } else if (checker.hasStraight()) {
            System.out.printf("%-20s\t", "Straight");
            return 5;
        } else if (checker.hasFlush()) {
            System.out.printf("%-20s\t", "Flush");
            return 4;
        } else if (checker.hasFourKind()) {
            System.out.printf("%-20s\t", "Four of kind");
            return 3;
        } else if (checker.hasThreeKind()) {
            System.out.printf("%-20s\t", "Three of kind");
            return 2;
        } else if (checker.hasTwoPairs()) {
            System.out.printf("%-20s\t", "Two pairs");
            return 1;
        } else if (checker.hasPair()) {
            System.out.printf("%-20s\t", "One pair");
            return 0;
        }
        System.out.printf("%-20s\t", "none");
        return -1;
    }
} // end class DeckOfCardsTest

