package Zad1;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.shape.Line;
import javafx.stage.Stage;


public class Main extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group();

        Scene scene = new Scene(group, 300, 300);
        drawLines(25, group, scene.getWidth(), scene.getHeight());

        // Set the Window title
        stage.setTitle("Draw mesh");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    private static void drawLines(int count, Group group, double width, double height) {
        double diagonal = Math.sqrt(width * width + height * height);
        int increments = (int) (diagonal / count);

        for (int i = 0; i < count; i++) {
            addLine(
                    new Line(0, 0,  i * increments, height - i * increments),
                    group);
        }
    }

    private static void addLine(Line line, Group group) {
        String color = "blue";
        setLineColor(line, color);
        group.getChildren().add(line);
    }

    private static void setLineColor(Line line, String color) {
        line.setStyle(String.format("-fx-stroke: %s", color));
    }
}