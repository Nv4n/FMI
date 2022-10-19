package Zad1;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.TextInputDialog;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Geometry extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group();
        Scene scene = new Scene(group, 500, 1000);
        Circle c = drawCircle(group, scene.getWidth(), scene.getHeight());
        Line l = drawLine(group, scene.getWidth(), scene.getHeight());
        drawIntersectionDots(group, l, c);

        // Set the Window title
        stage.setTitle("Geometry");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    private static Circle drawCircle(Group group, double width, double height) {
        double radius = Math.min(height, width) / 3;
        Circle circle = new Circle(width / 2, height / 2, radius);
        circle.setStyle("-fx-fill: red");
        group.getChildren().add(circle);

        return circle;
    }

    private static Line drawLine(Group group, double width, double height) {
        double x = -1;
        x = getX(width, x);
        double y = -1;
        y = getY(height, y);

        Line line = new Line(x, y, x, height);
        line.setStyle("-fx-stroke: blue");
        group.getChildren().add(line);

        return line;
    }

    private static double getY(double height, double y) {
        while (y < 0 || y > height) {
            TextInputDialog dialog = new TextInputDialog();
            dialog.setContentText("Y: ");
            dialog.setHeaderText("Y value for point A: ");
            dialog.showAndWait();
            y = Double.parseDouble(dialog.getResult());
        }
        return y;
    }

    private static double getX(double width, double x) {
        while (x < 0 || x > width) {
            TextInputDialog dialog = new TextInputDialog();
            dialog.setContentText("X: ");
            dialog.setHeaderText("X value for point A: ");
            dialog.showAndWait();
            x = Double.parseDouble(dialog.getResult());
        }
        return x;
    }

    private static void drawIntersectionDots(Group group, Line line, Circle circle) {

    }
}