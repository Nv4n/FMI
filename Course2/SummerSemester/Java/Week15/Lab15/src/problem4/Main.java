package problem4;

import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        List<String> strings = List.of("b", "a", "cc", "bb", "ddd");

        strings.stream()
                .collect(Collectors.groupingBy(String::length))
                .forEach((key, value) -> System.out.printf("Length %d:\t%s%n", key, value));

        System.out.println();
        strings.stream()
                .collect(Collectors.groupingBy(String::length, Collectors.counting()))
                .forEach((key, value) -> System.out.printf("Length %d:\t have %d elements%n", key, value));
    }
}
