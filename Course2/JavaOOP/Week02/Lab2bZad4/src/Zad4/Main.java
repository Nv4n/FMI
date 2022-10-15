package Zad4;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Main extends Application {

    private static void draw20ShapesIn4Corners(Group group, double width, double height) {
        int increments = 20;
        double widthStep = width / increments;
        double heightStep = height / increments;

        for (int index = 0; index < increments; index++) {
            Line line = new Line(width, heightStep * index, width - widthStep * (index + 1), height);
            line.setStyle("-fx-stroke: red");
            group.getChildren().add(line);
        }
        for (int index = 0; index < increments; index++) {
            Line line = new Line(0, height - heightStep * index, width - widthStep * (index + 1), height);
            line.setStyle("-fx-stroke: green");
            group.getChildren().add(line);
        }
        for (int index = 0; index < increments; index++) {
            Line line = new Line(width, height - heightStep * index, width - widthStep * (index + 1), 0);
            line.setStyle("-fx-stroke: blue");
            group.getChildren().add(line);
        }
        for (int index = 0; index < increments; index++) {
            Line line = new Line(0, heightStep * index, width - widthStep * (index + 1), 0);
            line.setStyle("-fx-stroke: yellow");
            group.getChildren().add(line);
        }
    }

    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group();
        Scene scene = new Scene(group, 300, 300);
        scene.setFill(Paint.valueOf("black"));
        draw20ShapesIn4Corners(group, scene.getWidth(), scene.getHeight());

        // Set the Window title
        stage.setTitle("Draw mesh of lines");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);

        stage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }
}