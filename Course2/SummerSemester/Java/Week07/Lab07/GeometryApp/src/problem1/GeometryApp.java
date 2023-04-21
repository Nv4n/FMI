package problem1;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.Random;

public class GeometryApp extends Application {

    @Override
    public void start(Stage stage) {

        Group root = new Group();

        Scene scene = new Scene(root, 500, 500);
//        test(root);
        drawRandomGeometry(root, scene.getWidth(), scene.getHeight());

        // Set the Window title
        stage.setTitle("Geometries");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    private void drawRandomGeometry(Group root, double width, double height) {
        Random rand = new Random();
        createRectangle(root, width, height, rand);
        createRectangle(root, width, height, rand);
    }

    private static void createRectangle(Group root, double width, double height, Random rand) {
        Point uPoint = new Point(
                rand.nextDouble(10, width - 100),
                rand.nextDouble(10, height - 100));
        Rectangle rect = new Rectangle(
                uPoint,
                rand.nextDouble(50, width / 4.0),
                rand.nextDouble(50, height / 4.0));

        rect.draw(root);

        drawDiagonals(root, uPoint, rect);
    }

    private static void drawDiagonals(Group root, Point uPoint, Rectangle rect) {
        Point ePoint1 = new Point(
                uPoint.getX() + rect.getWidth(),
                uPoint.getY() + rect.getHeight());
        Line diag1 = new Line(uPoint, ePoint1);

        diag1.draw(root);

        Point sPoint2 = new Point(
                uPoint.getX() + rect.getWidth(),
                uPoint.getY());
        Point ePoint2 = new Point(
                uPoint.getX(),
                uPoint.getY() + rect.getHeight());
        Line diag2 = new Line(sPoint2, ePoint2);

        diag2.draw(root);
    }

    private static void test(Group root) {
        Line line = new Line();
        line.draw(root);

        Rectangle rect = new Rectangle(new Point(10, 10), 400, 50);
        rect.draw(root);
    }

    public static void main(String[] args) {
        launch(args);
    }
}