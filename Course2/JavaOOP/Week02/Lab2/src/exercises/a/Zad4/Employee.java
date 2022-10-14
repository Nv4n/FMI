package exercises.a.Zad4;

public class Employee {
    private String firstName;
    private String lastName;
    private double monthlySalary;

    public Employee(String firstName, String lastName, double monthlySalary) {
        setFirstName(firstName);
        setLastName(lastName);
        setMonthlySalary(monthlySalary);
    }

    public String getFirstName() {
        return firstName;
    }

    //Employees shouldn't be able to change their name
    private void setFirstName(String firstName) {
        this.firstName = firstName != null ? firstName : "FirstName";
    }

    public String getLastName() {
        return lastName;
    }

    private void setLastName(String lastName) {
        this.lastName = lastName != null ? lastName : "LastName";
    }

    public String getFullName() {
        return String.format("%s %s", firstName, lastName);
    }

    public double getMonthlySalary() {
        return monthlySalary;
    }

    public void setMonthlySalary(double monthlySalary) {
        this.monthlySalary = monthlySalary > 0 ? monthlySalary : 0;
    }

}
