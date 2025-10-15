package model;

import java.time.LocalDate;

public class Person {
    private String firstName;
    private String lastName;
    private LocalDate hireDate;

    public Person(String firstName, String lastName, LocalDate hireDate) {
        setFirstName(firstName);
        setLastName(lastName);
        setHireDate(hireDate);
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public LocalDate getHireDate() {
        return hireDate;
    }

    public void setHireDate(LocalDate hireDate) {
        this.hireDate = hireDate;
    }
}
