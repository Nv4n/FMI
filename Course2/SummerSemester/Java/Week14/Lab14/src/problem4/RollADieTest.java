package problem4;

import java.util.Collections;
import java.util.Map;
import java.util.Random;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class RollADieTest {


    public static void main(String[] args) {
        Random rand = new Random();
        System.out.printf("%-5s%-10s%n", "Face", "Frequency");
        IntStream.rangeClosed(1, 6_000_000)
                .map(i -> rand.nextInt(0, 6) + 1).boxed()
                .collect(Collectors.groupingBy(num -> num, Collectors.summingInt(roll -> 1)))
                .forEach((num, rolls) -> {
                    System.out.printf("%-5d%-10d%n", num, rolls);
                });
    }

}
