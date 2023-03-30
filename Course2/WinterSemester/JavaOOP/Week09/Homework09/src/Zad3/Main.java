package Zad3;

import java.util.*;
import java.util.function.Supplier;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Stream<String> numberSequence =
                Stream.iterate(1, n -> n + 1).limit(100).map(String::valueOf);
        System.out.println(
                numberSequence.reduce((a, b) -> a + "#" + b).orElse(""));

        List<Integer> randomSequence = new Random().ints(20, 0, 30).boxed().toList();
        Supplier<Stream<Integer>> streamSupplier
                = randomSequence::stream;
        streamSupplier.get().forEach(num -> System.out.printf("%d ", num));
        System.out.println();

        boolean hasDividableBy5 = streamSupplier.get().anyMatch(a -> (a % 5) == 0);
        boolean areLowerThan15 = streamSupplier.get().allMatch(a -> a <= 15);

        double avg = streamSupplier.get().mapToInt(Integer::intValue).average().orElse(0);
        boolean hasAtLeast5LowerThanAvg = streamSupplier.get().filter(el -> el > avg).toArray().length > 5;

        System.out.printf("Has number dividable by 5: %b%n", hasDividableBy5);
        System.out.printf("All numbers are lower than 15: %b%n", areLowerThan15);
        System.out.printf("There are at least 5 numbers lower than the avg: %b%n", hasAtLeast5LowerThanAvg);
    }
}
