package model;

import java.util.Arrays;

public class AppointTest {
    public static void main(String[] args) {
        Manager boss = new Manager("Boss", 6000.86, "Invoices");
        Staff[] candidates = new Staff[]{
                new Staff("Gosho", 2300, null),
                new Staff("Maria", 1600.34, null)
        };
        System.out.println(boss);
        for (Staff candidate : candidates) System.out.println(candidate);
        HRdepartment hRdepartment = new HRdepartment(boss);
        StaffAppointHandler sah = hRdepartment.getAppointHandler();
        boss.addStaffAppointHandler(sah);

        boss.onStaffAppoint(candidates[0], 1300);
        boss.onStaffAppoint(candidates[1], 1500);
        System.out.println();
        System.out.println(sah.toString());
        System.out.println();
        for (Staff candidate : candidates) System.out.println(candidate);
    }
}
