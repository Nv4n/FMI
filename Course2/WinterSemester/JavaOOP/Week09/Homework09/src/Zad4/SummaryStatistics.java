/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Zad4;

import java.util.*;
import java.util.stream.Collectors;

/**
 * @author eck
 */
public class SummaryStatistics {

    private final List<Double> numbers = new ArrayList<>();
    private final List<Company> companies = new ArrayList<>();
    private final Random rand = new Random();

    private class Company {

        private final double revenue;

        public Company(double revenue) {
            this.revenue = revenue;
        }

        /**
         * Get the value of revenue
         *
         * @return the value of revenue
         */
        public double getRevenue() {
            return revenue;
        }

    }

    public void setupCompanies() {

        for (int i = 0; i < 10; i++) companies.add(new Company(rand.nextInt(101) / 10.0));
    }

    public void setup() {
        for (int i = 0; i < 10; i++) numbers.add(rand.nextInt(101) / 10.0);
    }

    public double companyStats() {
        DoubleSummaryStatistics stats = companies.stream()
                .collect(Collectors.summarizingDouble(Company::getRevenue));
        System.out.println("Company stats: " + stats);// print all the statistics!!!
        return stats.getAverage();
    }

    public double companyStatsWithStreamAverage() {
        return companies.stream().mapToDouble(Company::getRevenue).average().orElse(Double.NaN);
    }

    public double averageWithJava() {
        double sum = 0d;
        for (double number : numbers) sum += number;
        double average = numbers.size() > 0 ? sum / numbers.size() : 0d;
        System.out.println("Java Numbers average: " + average);
        return average;
    }

    public double statsWithStreamAverage() {
        // mapToDouble because it is a stream specialized to work with primitives!!!
        OptionalDouble average = numbers.stream().mapToDouble(Double::doubleValue).average();
        System.out.println("Stream Numbers average: " + average);
        if (average.isPresent())
            return average.getAsDouble();
        else return -1;
    }

    public double statsWithStreamMin() {
        // mapToDouble because it is a stream specialized to work with primitives!!!
        OptionalDouble min = numbers.stream().mapToDouble(Double::doubleValue).min();
        System.out.println("Stream Numbers min: " + min);
        if (min.isPresent())
            return min.getAsDouble();
        else return -1;
    }

    public double statsWithStreamReduce() {
        // Find the sum
        Optional<Double> sum = numbers.stream().reduce(Double::sum);
        System.out.println("Stream Numbers sum: " + sum);
        if (sum.isPresent())
            return sum.get();
        return -1;
    }

    public double allStatsWithStream() {
        // Find the sum
        DoubleSummaryStatistics stats = numbers.stream().collect(Collectors.summarizingDouble(Double::doubleValue));
        System.out.println(stats);// print all the statistics!!!
        System.out.println("Stream Numbers all stats: " + stats);
        return stats.getSum();
    }
}
