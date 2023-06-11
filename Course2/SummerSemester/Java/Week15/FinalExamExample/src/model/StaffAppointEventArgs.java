package model;

public class StaffAppointEventArgs {
    private final Staff staffMember;
    private final double salary;

    public StaffAppointEventArgs(Staff staffMember, double salary) {
        this.staffMember = new Staff(staffMember);
        this.salary = salary;
    }

    public Staff getStaffMember() {
        return staffMember;
    }

    public double getSalary() {
        return salary;
    }
}
