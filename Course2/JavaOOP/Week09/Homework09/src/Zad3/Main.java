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
        Supplier<Stream<Object>> streamSupplier
                = () -> Stream.of(randomSequence.toArray());
        streamSupplier.get().forEach(System.out::println);

        boolean isDividableBy5 = streamSupplier.get().anyMatch(a -> {
            if (a.getClass() == Integer.class)
                return ((Integer) a % 5) == 0;
            else return false;
        });
        boolean allLowerThan15 = streamSupplier.get().allMatch(a -> {
            if (a.getClass() == Integer.class)
                return (Integer) a <= 15;
            else return false;
        });
        int avg = Integer.parseInt(streamSupplier.get().reduce((a, b) -> (Integer) a + (Integer) b).orElse(0).toString()) / 20;

        boolean hasAtLeast5LowerThanAvg = streamSupplier.get().filter(a -> Integer.parseInt(a.toString()) > avg).toArray().length > 5;

        System.out.println(isDividableBy5);
        System.out.println(allLowerThan15);
        System.out.println(hasAtLeast5LowerThanAvg);
    }
}
