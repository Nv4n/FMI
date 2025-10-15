package problem2;

import java.util.Arrays;
import java.util.function.*;

public class LambdaTest {
    public static void main(String[] args) {
        System.out.println("2.a");
        //2.a
        //a
        Function<Integer, String> function = (num) -> {
            return Integer.toString(num);
        };
        System.out.println(function.apply(12).getClass());

        //b
        BiPredicate<Double, Double> biPredicate = (lvs, rvs) -> {
            return lvs > rvs;
        };
        System.out.println(biPredicate.test(12.0, 32.5));

        //c
        BiConsumer<String, String> biConsumer = (text1, text2) -> {
            //SOME FUNCTIONALITY
            text1 += text2;
            System.out.println(text1);
        };
        biConsumer.accept("SOme", " text");

        //d
        Supplier<int[]> supplier = () -> {
            int[] digits = new int[10];
            for (int i = 0; i < digits.length; i++) digits[i] = i;
            return digits;
        };
        System.out.println(Arrays.toString(supplier.get()));
        //e
        IntFunction<double[]> intFunction = (num) -> {
            double[] arrOfSize = new double[num];
            for (int i = 1; i < arrOfSize.length; i++)
                arrOfSize[i] = arrOfSize[i - 1] + 0.1;
            return arrOfSize;
        };
        System.out.println(Arrays.toString(intFunction.apply(6)));
        System.out.println("2.b");
        //2.b
        //a
        Function<Double, Double> func = Math::cos;
        //b
        Consumer<String> consumerTask = System.out::println;
        //c
        Runnable runnableTask = System.out::println;
        //d
        Predicate<String> isEqual = String::isEmpty;

        System.out.println("2.c");
        method((a) -> a + 0.1);
        method(Math::floor);
        method(func);

        System.out.println("2.d");
        Function<Double, Double> funcA = (x) -> Math.cos(x);
        Consumer<Object> consumerB = (x) -> System.out.println(x);
        Runnable runnableC = () -> System.out.println("Tова е Ламбда");
        BiPredicate<Integer, Integer> biPredicateD = (Integer x, Integer y) -> x > y;
        Predicate<Integer> predicateE = (Integer x) -> x % 2 == 0;
        BiFunction<Integer, Integer, Integer> biFunctionF = (Integer x, Integer y) -> x + y;
    }


    public static void method(Function<Double, Double>
                                      function) {

        System.out.println(function.apply(12.4));
    }
}
