package Zad2;

import java.util.Arrays;
import java.util.Scanner;

public class StreamTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a sentence with no punctuation: ");
        String text = input.nextLine();
        String[] txt = text.split("\\s+");

        Arrays.stream(txt)
                .map(String::toLowerCase)
                .distinct()
                .sorted()
                .forEach(System.out::println);
    }
}
