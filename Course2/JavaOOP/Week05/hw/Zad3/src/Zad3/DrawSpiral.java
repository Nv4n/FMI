package Zad3;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.shape.Line;
import javafx.scene.transform.Scale;
import javafx.stage.Stage;

public class DrawSpiral extends Application {

    private static final double INCREMENT = 10;

    @Override
    public void start(Stage stage) throws Exception {
        Group canvas = new Group();
        Scene scene = new Scene(canvas, 500, 500);
        setRightScale(scene);

        drawSpiral(canvas, scene);
        ChangeListener<Number> sizeListener = (a, b, c) -> {
            canvas.getChildren().clear();
            drawSpiral(canvas, scene);
            setRightScale(scene);

        };

        scene.heightProperty().addListener(sizeListener);
        scene.widthProperty().addListener(sizeListener);

        // Set the Window title
        stage.setTitle("Draw Square shaped spiral");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.TRUE);
        stage.setScene(scene);
        stage.show();
    }

    private void setRightScale(Scene scene) {
        Scale scale = new Scale(3, 3);
        scale.setPivotX(scene.getWidth() / 2);
        scale.setPivotY(scene.getHeight() / 2);
        scene.getRoot().getTransforms().setAll(scale);
    }

    public static void main(String[] args) {
        launch(args);
    }

    private void drawSpiral(Group canvas, Scene scene) {
        double centerX = scene.getWidth() / 2;
        double centerY = scene.getHeight() / 2;

        drawLineDown(centerX, centerY, 10, canvas);
    }

    private void drawLineDown(double startX, double startY, double size, Group canvas) {
        if (validateCoords(startX, startY, size)) return;

        Line line = new Line(startX, startY, startX, startY + size);
        line.setStyle("-fx-stroke: red");
        canvas.getChildren().add(line);

        drawLineLeft(startX, startY + size, size, canvas);
    }

    private void drawLineLeft(double startX, double startY, double size, Group canvas) {
        if (validateCoords(startX, startY, size)) return;

        Line line = new Line(startX, startY, startX - size, startY);
        line.setStyle("-fx-stroke: purple");
        canvas.getChildren().add(line);

        drawLineUp(startX - size, startY, size + INCREMENT, canvas);
    }

    private void drawLineUp(double startX, double startY, double size, Group canvas) {
        if (validateCoords(startX, startY, size)) return;

        Line line = new Line(startX, startY, startX, startY - size);
        line.setStyle("-fx-stroke: cyan");
        canvas.getChildren().add(line);

        drawLineRight(startX, startY - size, size, canvas);
    }

    private void drawLineRight(double startX, double startY, double size, Group canvas) {
        if (validateCoords(startX, startY, size)) return;

        Line line = new Line(startX, startY, startX + size, startY);
        line.setStyle("-fx-stroke: green");
        canvas.getChildren().add(line);

        drawLineDown(startX + size, startY, size + INCREMENT, canvas);
    }

    private boolean validateCoords(double startX, double startY, double size) {
        return /*startX + size >= paneWidth || startY + size >= paneHeight ||*/
                startX - size < 0 || startY - size < 0;
    }
}