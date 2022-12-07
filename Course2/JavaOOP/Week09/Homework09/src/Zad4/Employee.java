/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Zad4;

import java.time.LocalDate;
import java.time.Month;
import java.util.*;
import java.util.stream.Collectors;

/**
 * @author eck
 */
class Employee {

    public enum Gender {
        MALE, FEMALE
    }

    private String name;
    private Gender gender;
    private LocalDate dob;
    private double income;

    private UUID employeeID;

    private Employee(String name, Gender gender, LocalDate dob,
                     double income) {

        this.name = name;
        this.gender = gender;
        this.dob = dob;
        this.income = income;
        employeeID = UUID.randomUUID();
    }

    public Employee() {
    }

    public double getIncome() {
        return income;
    }

    public static List<Employee> persons() {
        Employee p1 = new Employee("Jake", Gender.MALE, LocalDate.of(1971,
                Month.JANUARY, 1), 2343.0);
        Employee p2 = new Employee("Jack", Gender.MALE, LocalDate.of(1972,
                Month.JULY, 21), 7100.0);
        Employee p3 = new Employee("Jane", Gender.FEMALE, LocalDate.of(1973,
                Month.MAY, 29), 5455.0);
        Employee p4 = new Employee("Jode", Gender.MALE, LocalDate.of(1974,
                Month.OCTOBER, 16), 1800.0);
        Employee p5 = new Employee("Jeny", Gender.FEMALE, LocalDate.of(1975,
                Month.DECEMBER, 13), 1234.0);
        Employee p6 = new Employee("Jason", Gender.MALE, LocalDate.of(1976,
                Month.JUNE, 9), 3211.0);

        return Arrays.asList(p1, p2, p3, p4, p5, p6);
    }

    public static void statistics() {
        System.out.printf("Total income: %.2f",
                persons().stream().mapToDouble(Employee::getIncome).sum());
    }

    public void personsStatsByGenderCount() {
        TreeMap<Gender, Integer> genderCounts = new TreeMap<>();
        for (Employee e : persons()) genderCounts.merge(e.gender, 1, Integer::sum);
        genderCounts.forEach((g, v) -> System.out.printf("%s: %d%n", g, v));

    }

    public void personsStatsByGenderList() {
        Map<Gender, List<Employee>> genderGroups =
                persons().stream()
                        .collect(Collectors.groupingBy(e -> e.gender, TreeMap::new, Collectors.toList()));
        genderGroups.forEach((g, employees) -> {
            System.out.printf("%s: ", g);
            System.out.println(employees.stream().map(Employee::toString).reduce((a, b) -> a + ", " + b).orElse("NONE"));
        });
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Employee employee = (Employee) o;
        return Double.compare(employee.income, income) == 0
                && Objects.equals(name, employee.name)
                && gender == employee.gender && Objects.equals(dob, employee.dob)
                && Objects.equals(employeeID, employee.employeeID);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, gender, dob, income, employeeID);
    }

    @Override
    public String toString() {
        return "Employee{" + "name='" + name + '\'' +
                ", gender=" + gender +
                ", dob=" + dob +
                ", income=" + income +
                ", employeeID=" + employeeID +
                '}';
    }
}

