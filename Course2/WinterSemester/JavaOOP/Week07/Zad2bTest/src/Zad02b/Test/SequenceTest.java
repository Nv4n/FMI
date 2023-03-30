package Zad02b.Test;

import Zad02b.SelectorBackwards;
import Zad02b.SelectorForward;
import Zad02b.SelectorTwoWay;
import Zad02b.Sequence;

import java.util.Random;

public class SequenceTest {
    public static void main(String[] args) {
        Sequence sequence = new Sequence(8);
        Random random = new Random();
        for (int i = 0; i < 8; i++)
            sequence.add(random.nextInt(91) + 10);

        SelectorBackwards selBack = sequence.getSelectorBackward();
        SelectorForward selForward = sequence.getSelectorForward();
        SelectorTwoWay selTwoWay = sequence.getSelectorTwoWay();

        System.out.println("Backward");
        printSeq(selBack);
        System.out.println("\nForward");
        printSeq(selForward);
        System.out.println("\nTwo way");
        printSeq(selTwoWay);

    }

    private static void printSeq(SelectorBackwards backwards) {
        while (!backwards.begin()) {
            System.out.printf("%s ", backwards.current());
            backwards.previous();
        }
    }

    private static void printSeq(SelectorForward forward) {
        while (!forward.end()) {
            System.out.printf("%s ", forward.current());
            forward.next();
        }
    }

    private static void printSeq(SelectorTwoWay twoWay) {
        while (!twoWay.end()) {
            System.out.printf("%s ", twoWay.current());
            twoWay.next();
        }
        twoWay.previous();
        while (!twoWay.begin()) {
            System.out.printf("%s ", twoWay.current());
            twoWay.previous();
        }
    }
}
