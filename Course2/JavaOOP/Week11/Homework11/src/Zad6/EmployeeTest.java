package Zad6;

import org.junit.Before;

import java.time.LocalDate;
import java.time.Month;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class EmployeeTest {
    static List<Employee> employees;

    @Before
    public static void setup() {
        employees = new ArrayList<>();
        employees.add(new Employee(123, "Jack", "Johnson", LocalDate.of(1988,
                Month.APRIL, 12)));
        employees.add(new Employee(345, "Cindy", "Bower", LocalDate.of(2011,
                Month.DECEMBER, 15)));
        employees.add(new Employee(567, "Perry", "Node", LocalDate.of(2005,
                Month.JUNE, 7)));
        employees.add(new Employee(467, "Pam", "Krauss", LocalDate.of(2005,
                Month.JUNE, 7)));
        employees.add(new Employee(435, "Fred", "Shak", LocalDate.of(1988,
                Month.APRIL, 17)));
        employees.add(new Employee(678, "Ann", "Lee", LocalDate.of(2007,
                Month.APRIL, 12)));
    }

    public static void main(String[] args) {
        setup();
        System.out.println(employees.stream()
                .sorted(
                        Comparator.comparing(Employee::getEmployeeNumber))
                .map(Employee::toString)
                .reduce("", (acc, el) -> acc + "\n" + el));
    }
}

