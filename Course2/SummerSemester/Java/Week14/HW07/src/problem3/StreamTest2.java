package problem3;

import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class StreamTest2 {
    public static void main(String[] args) {
        IntStream.range(1, 100)
                .mapToObj(Integer::toString)
                .reduce((s1, s2) -> s1 + "#" + s2)
                .ifPresent(System.out::println);
        List<Integer> nums = new Random()
                .ints(20, 0, 31)
                .boxed()
                .toList();

        nums.forEach(System.out::println);
        boolean div5 = nums.stream().anyMatch(n -> n % 5 == 0);
        boolean allUnder15 = nums.stream().allMatch(n -> n < 15);
        boolean countAbove5 = nums.stream()
                .filter(n -> n > nums.stream()
                        .mapToInt(Integer::intValue)
                        .average()
                        .orElse(0))
                .count() > 5;

        System.out.printf("""
                Has any dividable by 5: %b
                All under 15: %b
                Count of nums above avg is above 5: %b
                """, div5, allUnder15, countAbove5);
    }
}
