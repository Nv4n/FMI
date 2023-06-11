package model;

import java.security.InvalidParameterException;
import java.util.ArrayList;

public class Manager extends Employee {
    private String manageDeptName;
    private StaffAppointHandler staffAppoint;

    public Manager() {
        super();
        setManageDeptName("No dept");
    }

    public Manager(String name, double salary, String manageDeptName) {
        super(name, salary);
        setManageDeptName(manageDeptName);
    }

    public Manager(Manager other) {
        super(other);
        setManageDeptName(other.getManageDeptName());
    }

    public void addStaffAppointHandler(StaffAppointHandler staffAppoint) {
        this.staffAppoint = staffAppoint;
    }

    public void onStaffAppoint(Staff member, double newStaffMemberSalary) {
        if (staffAppoint != null) staffAppoint.addStaff(new StaffAppointEventArgs(member, newStaffMemberSalary));
    }

    public String getManageDeptName() {
        return manageDeptName;
    }

    public void setManageDeptName(String manageDeptName) {
        if (manageDeptName == null)
            throw new InvalidParameterException("Manage Dept name can't be null");
        this.manageDeptName = manageDeptName;
    }

    @Override
    public String toString() {
        return String.format("%s, Department name: %s",
                super.toString(), manageDeptName);
    }
}
