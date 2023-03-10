package com.problem1;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.TextArea;
import javafx.stage.Stage;

import java.util.Calendar;

public class CalendarGenerator extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        Group root = new Group();

        Scene scene = new Scene(root, 500, 400);
        doSomething(root);


        // Set the Window title
        stage.setTitle("Calendar");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    private void doSomething(Group root) {
        TextArea calendarArea = new TextArea();
        Calendar calendar = Calendar.getInstance();
        int maximum = calendar.getMaximum(Calendar.DAY_OF_WEEK);
//        calendar.set
    }

    public static void main(String[] args) {
        launch(args);
    }
}