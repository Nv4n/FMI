package Zad4;

import java.util.Random;
import java.util.function.Function;
import java.util.stream.Collectors;

public class RollFrequency {
    public static void main(String[] args) {
        System.out.println("Face Frequency");
        Random random = new Random();
        random.ints(6_000_000, 1, 7)
                .boxed()
                .collect(Collectors.groupingBy(Function.identity(),
                        Collectors.counting()))
                .forEach((face, frequency) -> {
                    System.out.printf("%-5d%d%n", face, frequency);
                });
    }
}
