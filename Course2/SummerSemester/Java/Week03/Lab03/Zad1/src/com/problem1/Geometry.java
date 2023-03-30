package com.problem1;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.control.TextInputDialog;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Geometry extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        Group root = new Group();

        Scene scene = new Scene(root, 400, 500);

        drawCircle(root, scene.getWidth(), scene.getHeight());
        TextInputDialog inputDialog = new TextInputDialog();
        inputDialog.setHeaderText("Enter starting X for the line");
        double startingX = Double.parseDouble(
                inputDialog.showAndWait()
                        .orElse(
                                Double.toString(scene.getWidth() / 2)));

        drawLine(root, startingX, scene.getHeight(), scene.getWidth());
        drawIntersections(root, startingX, scene.getHeight(), scene.getWidth());


        // Set the Window title
        stage.setTitle("Draw geometry");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    private void drawIntersections(Group root, double x, double height, double width) {
        double radius = Math.min(width, height) / 3.0;
        double centerX = width / 2.0;
        double centerY = height / 2.0;

        double distanceX = x - centerX;
        if (Math.abs(distanceX) > radius) {
            new Alert(Alert.AlertType.WARNING, "There aren't any intersections").showAndWait();
            Platform.exit();
            System.exit(0);
        }
        double distanceY = Math.sqrt(radius * radius - distanceX * distanceX);

        double coordYUpperPoint = centerY - distanceY;
        Ellipse upperPoint = new Ellipse(x, coordYUpperPoint, 3, 3);
        upperPoint.setFill(Paint.valueOf("purple"));

        double coordYLowerPoint = centerY + distanceY;
        Ellipse lowerPoint = new Ellipse(x, coordYLowerPoint, 3, 3);
        lowerPoint.setFill(Paint.valueOf("purple"));

        addLabel(root, x, coordYUpperPoint);
        addLabel(root, x, coordYLowerPoint);

        root.getChildren().add(upperPoint);
        root.getChildren().add(lowerPoint);
    }

    private static void addLabel(Group root, double x, double y) {
        Label label = new Label(String.format("[%.2f,%.2f]", x, y));
        label.setLayoutX(x + 10);
        label.setLayoutY(y);
        root.getChildren().add(label);
    }

    private void drawLine(Group root, double x, double height, double width) {
        if (x > width || x < 0) {
            new Alert(Alert.AlertType.WARNING, "Line's x coordinate is out of scene").showAndWait();
            Platform.exit();
            System.exit(0);
        }
        Line line = new Line(x, 0, x, height);
        line.setStroke(Paint.valueOf("blue"));
        root.getChildren().add(line);
    }

    private static void drawCircle(Group root, double width, double height) {
        double radius = Math.min(width, height) / 3.0;
        Circle circle = new Circle(width / 2.0, height / 2.0, radius);
        circle.setFill(Paint.valueOf("transparent"));
        circle.setStroke(Paint.valueOf("red"));
        root.getChildren().add(circle);
    }

    public static void main(String[] args) {
        launch(args);
    }
}