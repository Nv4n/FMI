package Zad2;

import java.util.List;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Stream<String> stringStream = Stream.of("aBc", "d", "ef", "123456");
        List<String> stringList = stringStream
                .map(String::toUpperCase)
                .sorted(CharSequence::compare)
                .toList();
        stringList.forEach(System.out::println);
    }
}
