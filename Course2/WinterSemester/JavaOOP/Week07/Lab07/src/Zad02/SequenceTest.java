package Zad02;

import java.util.Random;
import java.util.Scanner;

public class SequenceTest {
    public static void main(String[] args) {
// (1)създайте Sequence последователност от 8 елемента
// (2)инициализирайте Sequence елементите
// със случайни цели числа от интервала [10, 100]
// (3)използвайте метода getSelector(),за да разпечатате
// тези числа на конзолата
// от първия до последния елемент на последователността
// (4)използвайте метода getRSelector(),за да разпечатате
// на конзолата тези числа
// от последния елемент до първия на последователността
        Random randNum = new Random();
        Sequence seq = new Sequence(8);

        for (int i = 0; i < 8; i++)
            seq.add(randNum.nextInt(91) + 10);
        System.out.println("Sequence");
        Selector selector = seq.getSelector();
        printSeq(selector);
        System.out.println("\nReversed");
        Selector rSelector = seq.getRSelector();
        printSeq(rSelector);
    }

    private static void printSeq(Selector selector) {
        while (!selector.end()) {
            System.out.printf("%s ", selector.current());
            selector.next();
        }
    }

}
