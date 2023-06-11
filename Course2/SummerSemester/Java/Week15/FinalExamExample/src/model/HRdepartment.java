package model;

import java.security.InvalidParameterException;
import java.util.ArrayList;

public class HRdepartment {
    private Manager manager;
    private final ArrayList<Staff> staff;

    public HRdepartment(Manager manager) {
        setManager(manager);
        staff = new ArrayList<>();
    }

    public Manager getManager() {
        return new Manager(manager);
    }

    public void setManager(Manager manager) {
        if (manager == null)
            throw new InvalidParameterException("HR department must have manager");
        this.manager = new Manager(manager);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("HRdepartment{");
        sb.append("manager=").append(manager);
        sb.append(", staff: {\n");
        for (int i = 0; i < staff.size(); i++)
            sb.append(String.format("#%d %s%n", i + 1, staff.get(i).toString()));
        sb.append('}');
        return sb.toString();
    }

    public StaffAppointHandler getAppointHandler() {
        return new NewStaffHandler(manager.getManageDeptName());
    }

    private class NewStaffHandler implements StaffAppointHandler {
        private String appointDepartment;

        public NewStaffHandler(String appointDepartment) {
            setAppointDepartment(appointDepartment);
        }

        @Override
        public void addStaff(StaffAppointEventArgs args) {
            args.getStaffMember().setWorkAt(appointDepartment);
            args.getStaffMember().setSalary(args.getSalary());
            staff.add(new Staff(args.getStaffMember()));
        }

        public String getAppointDepartment() {
            return appointDepartment;
        }

        public void setAppointDepartment(String appointDepartment) {
            if (appointDepartment == null) throw new InvalidParameterException("Must have department");
            this.appointDepartment = appointDepartment;
        }

        @Override
        public String toString() {
            return String.format("%s, Appoint dept: %s",
                    HRdepartment.this.toString(), appointDepartment);
        }
    }
}
