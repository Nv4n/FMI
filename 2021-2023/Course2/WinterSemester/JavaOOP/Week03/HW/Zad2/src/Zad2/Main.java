package Zad2;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Main extends Application {

    private static void draw20ShapesIn4Corners(Group group, double width, double height) {
        group.getChildren().clear();
        int increments = 20;
        double widthStep = width / increments;
        double heightStep = height / increments;

        for (int index = 0; index < increments; index++) {
            Line line = new Line(0, height - heightStep * index, width - widthStep * (index + 1), height);
            line.setStyle("-fx-stroke: blue");
            group.getChildren().add(line);
        }
    }

    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group();
        Scene scene = new Scene(group, 300, 500);
        draw20ShapesIn4Corners(group, scene.getWidth(), scene.getHeight());

        ChangeListener<Number> stageSizeListener = (observable, oldValue, newValue) ->
                draw20ShapesIn4Corners(group, scene.getWidth(), scene.getHeight());

        stage.widthProperty().addListener(stageSizeListener);
        stage.heightProperty().addListener(stageSizeListener);

        // Set the Window title
        stage.setTitle("Draw mesh of lines");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.TRUE);
        stage.setScene(scene);

        stage.show();

    }


    public static void main(String[] args) {
        launch(args);
    }
}