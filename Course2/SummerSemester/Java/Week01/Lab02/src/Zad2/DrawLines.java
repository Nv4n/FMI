package Zad2;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Ellipse;
import javafx.stage.Stage;

public class DrawLines extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        Group root
                = new Group();
        Scene scene = new Scene(root, 400, 600);
        drawCircles(root, scene);

        // Set the Window title
        stage.setTitle("Circles");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    private void drawCircles(Group root, Scene scene) {
        double centerX = scene.getWidth() / 2;
        double centerY = scene.getHeight() / 2;
        double diameter = 20;
        while (diameter <= scene.getWidth() && diameter <= scene.getHeight()) {
            drawCircle(diameter, centerX, centerY, root);
            diameter += 20;
        }
    }

    public static void main(String[] args) {
        launch(args);
    }

    public void drawCircle(double diameter, double centerX, double centerY, Group group) {
        double radius = diameter / 2;
        Ellipse currentCircle = new Ellipse(centerX, centerY, radius, radius);
        currentCircle.setFill(Paint.valueOf("transparent"));
        currentCircle.setStroke(Paint.valueOf("black"));
        group.getChildren().add(currentCircle);
    }
}