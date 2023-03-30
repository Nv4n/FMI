package com.problem1;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.TextInputDialog;
import javafx.scene.paint.Paint;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.Month;
import java.time.temporal.Temporal;
import java.time.temporal.TemporalAccessor;

public class CalendarGenerator extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        Group root = new Group();

        Scene scene = new Scene(root, 400, 200);
        addDayOfWeek(root);
        TextInputDialog input = new TextInputDialog();

        input.setHeaderText("Enter month:");
        int month = Integer.parseInt(input.showAndWait().orElse("1"));
        if (month < 1 || month > 12) month = 1;

        input.setHeaderText("Enter year:");
        input.getEditor().clear();
        int year = Integer.parseInt(input.showAndWait().orElse("2023"));
        if (year < 1900 || year > 2100) year = 2023;

        addDays(root, month, year);
        // Set the Window title
        stage.setTitle(String.format("Calendar for %s %d", Month.of(month).toString(), year));
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    private void addDayOfWeek(Group root) {
        double step = 50;
        double xCoord = 50;
        for (int i = 1; i <= 7; i++) {
            Text dayOfWeekTxt = new Text(xCoord, 50, DayOfWeek.of(i).toString().substring(0, 3));
            dayOfWeekTxt.setStyle("-fx-font-weight: bold");
            root.getChildren().add(dayOfWeekTxt);
            xCoord += step;
        }
    }

    private void addDays(Group root, int month, int year) {
        LocalDate date = LocalDate.of(year, month, 1);
        LocalDate now = LocalDate.now();
        boolean isInSameMonth = date.getMonth() == now.getMonth() && date.getYear() == now.getYear();
        int nowDay = isInSameMonth ? now.getDayOfMonth() : -1;
        System.out.println(nowDay);
        double offset = date.getDayOfWeek().getValue();
        double x = offset * 50;
        double y = 70;
        for (int day = 1; day <= 31; day++) {
            if (x > 7 * 50) {
                x = 50;
                y += 20;
            }
            Text dayTxt = new Text(x, y, Integer.toString(day));
            x += 50;
            dayTxt.setStyle("-fx-font-weight: bold");

            if (day == nowDay) {
                dayTxt.setFill(Paint.valueOf("red"));
            }
            root.getChildren().add(dayTxt);
        }

//        calendar.set
    }

    public static void main(String[] args) {
        launch(args);
    }
}