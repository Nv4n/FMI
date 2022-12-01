package Zad1;

import org.jetbrains.annotations.NotNull;

public class Salesperson {
    private final String name;
    private double salary;
    private final int numsales;

    public Salesperson(String name, double salary, int numsales) {
        this.name = name;
        this.salary = salary;
        this.numsales = numsales;
    }

    public void addBonus(double amount) {
        salary += amount;
    }

    public int getNumSales() {
        return numsales;
    }

    public double getSalary() {
        return salary;
    }

    public String getName() {
        return name;
    }

    public void printNumSales(@NotNull Salesperson obj) {
        System.out.println(obj.getNumSales());
    }

    @Override
    public String toString() {
        return String.format("name: %s, salary: %.2f numsales: %d",
                name, salary, numsales);
    }
}
