package com.app;

import java.sql.*;


public class DB2Manager {
    private Connection connection;

    public DB2Manager() {
        try {
            Class.forName("com.ibm.db2.jcc.DB2Driver");
        } catch (ClassNotFoundException e) {
            System.out.println("Please include Classpath  Where your DB2 Driver is located");
            e.printStackTrace();
        }
        System.out.println("DB2 driver is loaded successfully");
        connect();
    }

    public void connect() {
        try {
            connection = DriverManager.getConnection(
                    System.getenv("DB_URL"),
                    System.getenv("DB_USER"),
                    System.getenv("DB_PASS"));
            if (connection != null)
                System.out.println("DB2 Database Connected");
            else
                System.out.println("Db2 connection Failed ");

        } catch (SQLException e) {
            System.out.println("DB2 Database connection Failed");
            e.printStackTrace();
        }
    }

    public void disconnect() {
        try {
            connection.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void select(String statement) {
        PreparedStatement pstmt;
        ResultSet rset;
        boolean found = false;

        try {
            assert connection != null;
            pstmt = connection.prepareStatement(statement);
            rset = pstmt.executeQuery();
            ResultSetMetaData metaData = rset.getMetaData();

            for (int i = 1; i <= metaData.getColumnCount(); i++) {
                String columnName = metaData.getColumnName(i);
                System.out.printf("%50s ", columnName);
            }
            System.out.println();

            while (rset.next()) {
                found = true;
                for (int i = 1; i <= metaData.getColumnCount(); i++) {
                    Object columnValue = rset.getObject(i);
                    System.out.printf("%50s ", columnValue);
                }
                System.out.println();
            }
            if (!found) System.out.println("No Information Found");
        } catch (SQLException exception) {
            throw new RuntimeException(exception);
        }

        try {
            pstmt.close();
            rset.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }

    public void insert(String statement) {
        update(statement);

    }

    public void delete(String statement) {
        update(statement);

    }

    private void update(String statement) {
        PreparedStatement pstmt;

        try {
            assert connection != null;
            pstmt = connection.prepareStatement(statement);
            int rows = pstmt.executeUpdate();
            System.out.printf("Rows changed: %d%n", rows);

        } catch (SQLException exception) {
            throw new RuntimeException(exception);
        }

        try {
            pstmt.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

}
