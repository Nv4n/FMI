package model;

import java.time.LocalDate;
import java.util.concurrent.atomic.AtomicInteger;

public class Employee {
    private static final AtomicInteger ID = new AtomicInteger(0);
    private Integer id;
    private String firstName;
    private String lastName;
    private String email;
    private String phone;
    private double salary;
    private LocalDate birthday;

    public Employee(String firstName, String lastName, String email, String phone, double salary, LocalDate birthday) {
        setId(incrementAndGet());
        setFirstName(firstName);
        setLastName(lastName);
        setEmail(email);
        setPhone(phone);
        setSalary(salary);
        setBirthday(birthday);
    }

    public int getId() {
        return id;
    }

    private void setId(int id) {
        this.id = id;
    }

    public int incrementAndGet() {
        return ID.incrementAndGet();
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public LocalDate getBirthday() {
        return birthday;
    }

    public void setBirthday(LocalDate birthday) {
        this.birthday = birthday;
    }
}
