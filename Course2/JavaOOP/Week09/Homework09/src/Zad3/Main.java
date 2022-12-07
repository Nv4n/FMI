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
        streamSupplier.get().forEach(System.out::println);

        boolean isDividableBy5 = streamSupplier.get().anyMatch(a -> (a % 5) == 0);
        boolean allLowerThan15 = streamSupplier.get().allMatch(a -> a <= 15);

        double avg = streamSupplier.get().mapToInt(Integer::intValue).average().orElse(0);
        boolean hasAtLeast5LowerThanAvg = streamSupplier.get().filter(el -> el > avg).toArray().length > 5;

        System.out.println(isDividableBy5);
        System.out.println(allLowerThan15);
        System.out.println(hasAtLeast5LowerThanAvg);
    }
}
