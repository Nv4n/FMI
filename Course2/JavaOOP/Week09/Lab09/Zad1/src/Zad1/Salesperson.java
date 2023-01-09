package Zad1;

import org.jetbrains.annotations.NotNull;

import java.util.Objects;

public class Salesperson implements IAdder<Salesperson> {
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


    @Override
    public String printNode() {
        return String.format("name: %s, salary: %.2f numsales: %d",
                name, salary, numsales);
    }

    @Override
    public Salesperson add(Salesperson op1, Salesperson op2) {
        return new Salesperson(op1.getName(), op1.getSalary(), op1.getNumSales() + op2.getNumSales());
    }

    @Override
    public String printNumSales(Salesperson obj) {
        return String.format("Sales: %s", IAdder.super.printNumSales(obj));
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Salesperson that = (Salesperson) o;

        return this.getName().equals(that.getName());
    }

    @Override
    public int hashCode() {
        return name != null ? name.hashCode() : 0;
    }
}
