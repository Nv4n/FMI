package Zad3;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.TextInputDialog;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Sine extends Application {
    private static final double padding = 14;

    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group();

        Scene scene = new Scene(group, 1000, 300);
        drawSine(group, scene.getWidth(), scene.getHeight());
        // Set the Window title
        stage.setTitle("Sine");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    private static void drawSine(Group group, double width, double height) {
        int count = getDiscretePointsCount();
        drawXAxis(group, width, height);

        double interval = (width - 2 * padding) / 90;
        System.out.println(interval);
        double prevX = padding;
        double prevY = getY(height, prevX, interval);

        for (int i = 0; i < count; i++) {
            double currX = prevX + interval * 90 / count;

            double currY = getY(height, currX, interval);
            Circle circle = new Circle(currX, currY, 5);
            circle.setStyle("-fx-fill: red");
            group.getChildren().add(circle);

            // FIXME: 10/19/2022
            //  Find the formula for Y

            double miniInterval = interval * 9 / count;
            Line line;
            for (double x = prevX + miniInterval; x <= currX; x += miniInterval) {
                double y = getY(height, x, interval);
                System.out.printf("X: %.2f\tY: %.2f%n", x, y);

                line = new Line(prevX, prevY, x, y);
                line.setStyle("-fx-stroke: red");

                prevX = x;
                prevY = y;
                group.getChildren().add(line);
            }
        }
    }

    private static double getY(double height, double prevX, double interval) {
        return Math.sin(Math.toRadians((prevX - padding) / interval)) * (-height / 2) + (height / 2);
    }

    private static int getDiscretePointsCount() {
        TextInputDialog dialog = new TextInputDialog();
        dialog.setHeaderText("Discrete points count: ");
        dialog.setContentText("Value: ");
        dialog.showAndWait();
        return Integer.parseInt(dialog.getResult());
    }

    private static void drawXAxis(Group group, double width, double height) {
        Line axis = new Line(padding, height / 2, width - padding, height / 2);
        axis.setStyle("-fx-stroke: black");
        group.getChildren().add(axis);
    }
}
