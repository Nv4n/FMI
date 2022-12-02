package Zad3;

import java.util.List;
import java.util.Random;
import java.util.function.Supplier;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Stream<String> numberSequence =
                Stream.iterate(1, n -> n + 1).limit(100).map(String::valueOf);
        System.out.println(
                numberSequence.reduce((a, b) -> a + "#" + b).get());

        List<Integer> randomSequence = new Random().ints(5, 0, 30).boxed().toList();
        Supplier<Stream<Object>> streamSupplier
                = () -> Stream.of(randomSequence.toArray());
        streamSupplier.get().forEach(System.out::println);

        boolean div5 = streamSupplier.get().anyMatch(a -> {
            if (a.getClass() == Integer.class)
                return ((Integer) a % 5) == 0;
            else return false;
        });
        boolean low15 = streamSupplier.get().allMatch(a -> {
            if (a.getClass() == Integer.class)
                return (Integer) a <= 15;
            else return false;
        });
        System.out.println(div5);
        System.out.println(low15);
    }
}
