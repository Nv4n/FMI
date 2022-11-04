package Zad1;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.Random;

public class Main extends Application {
    private static Random randomNumber;

    @Override
    public void start(Stage stage) {
        Group group = new Group();
        Scene scene = new Scene(group, 750, 750);
        randomNumber = new Random();
        generateNRectangles(group, scene, 2);

        // Set the Window title
        stage.setTitle("");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    private static void generateNRectangles(Group group, Scene scene, int n) {
        for (int i = 0; i < n; i++)
            testGeometry(group, scene.getWidth(), scene.getHeight());
    }


    public static void main(String[] args) {
        launch(args);
    }

    private static void testGeometry(Group pane, double width, double height) {
        Point rectStart = new Point(
                randomNumber.nextDouble(width / 2),
                randomNumber.nextDouble(height / 2));

        Rectangle rect = new Rectangle(rectStart,
                randomNumber.nextDouble(width / 2),
                randomNumber.nextDouble(height / 2));

        Line mainDiagonal = new Line(
                rect.getUPoint(),
                new Point(
                        rect.getUPoint().getX() + rect.getWidth(),
                        rect.getUPoint().getY() + rect.getHeight()));

        Line secondDiagonal = new Line(
                new Point(
                        rect.getUPoint().getX() + rect.getWidth(),
                        rect.getUPoint().getY()),
                new Point(
                        rect.getUPoint().getX(),
                        rect.getUPoint().getY() + rect.getHeight()));

        rect.draw(pane);
        mainDiagonal.draw(pane);
        secondDiagonal.draw(pane);
    }

}