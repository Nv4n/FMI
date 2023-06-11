package com.app;

public class DbApp {
    public static void main(String[] args) {
        DB2Manager db2 = new DB2Manager();
        String statement = " INSERT INTO FN3MI0700035.STUDENTS (FN, FNAME, LNAME, FACULTY, COURSE) " +
                "VALUES ('BGFD4324FW', 'Мартин', 'Самуилов', 'Богословски', 3)";
        db2.insert(statement);
        System.out.println();
        statement = "SELECT FNAME, LNAME FROM FN3MI0700035.STUDENTS";
        db2.select(statement);
        System.out.println();
        statement = """
                DELETE FROM FN3MI0700035.STUDENTS
                WHERE FN= 'BGFD4324FW'
                """;
        db2.delete(statement);
        statement = "SELECT * FROM FN3MI0700035.STUDENTS";
        db2.select(statement);
        System.out.println();
        db2.disconnect();
    }
}
