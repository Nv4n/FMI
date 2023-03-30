package Zad2;

import java.util.Comparator;
import java.util.Objects;
import java.util.function.*;

public class Main {
    public static void main(String[] args) {
        // 2a)
//    Function<Integer, String> func = (num) -> String.valueOf(num);
//    BiPredicate<Double, Double> pred = (a, b) -> a > b;
//    BiConsumer<String, String> biConsumer = (k, v) -> System.out.printf("%s: %s", k, v);
//    Supplier<int[]> supplier = () -> new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    IntFunction<double[]> intFunction = (size) -> new double[size];

        // 2b)
//    Function<Double, Double> func = Math::cos;
//    Consumer<String> task = System.out::println;
//    Runnable task2 = System.out::println;
//    Predicate<String> isEqual = String::isEmpty;

        // 2c)

        method((a) -> Math.sqrt(a));
        method(Main::testMethod);
//        method(Main::testMethodNonStatic);

        // 2d)
//    Function<Double, Double> dub = (x) -> Math.cos(x);
//    Consumer<String> print = (x) -> System.out.println(x);
//    Runnable run = () -> System.out.println("Tова е Ламбда");
//    BiPredicate<Integer, Integer> pred = (int x, int y) -> x > y;
//    Predicate<Integer> pred = (int x) -> x % 2 == 0;
//    BiFunction<Integer, Integer, Integer> biConsumer = (int x, int y) -> x + y;
    }

    public static void method(Function<Double, Double> function) {

    }

    public static double testMethod(Double someDouble) {
        return Math.sqrt(someDouble);
    }

    public double testMethodNonStatic(Double someDouble) {
        return Math.sqrt(someDouble);
    }
}


