package exercises.Zad4;

public class EmployeeTest {
    public static void main(String[] args) {
        Employee employee1 = new Employee("Pesho", "Tashev", 650);
        Employee employee2 = new Employee("Galya", "Tihomirova", 1800);

        //display employees
        displayEmployee(employee1);
        displayEmployee(employee2);
        System.out.println();

        //10% salary raise
        employee1.setMonthlySalary(employee1.getMonthlySalary() * 1.1);
        employee2.setMonthlySalary(employee2.getMonthlySalary() * 1.1);

        //display employees
        displayEmployee(employee1);
        displayEmployee(employee2);
    }

    private static void displayEmployee(Employee employee) {
        System.out.printf("Name:\t%s%nYearly salary:\t$%,.2f%n",
                employee.getFullName(),
                employee.getMonthlySalary() * 12);
    }
}
