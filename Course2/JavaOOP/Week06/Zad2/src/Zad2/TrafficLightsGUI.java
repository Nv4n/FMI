package Zad2;

import javafx.application.Application;
import javafx.concurrent.Service;
import javafx.concurrent.Task;
import javafx.concurrent.WorkerStateEvent;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class TrafficLightsGUI extends Application {
    private static final double CIRCLE_RADIUS = 100;
    private static final double CIRCLE_MARGIN = 25;

    private static Service lightsChanger;
    private static int lightI;

    private static long prevMilliseconds;

    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group();
        Scene scene = new Scene(group, 500, 900);
        scene.setFill(Paint.valueOf("black"));
        setup(group, scene.getWidth());
        // Set the Window title
        stage.setTitle("TRAFFIC LIGHT");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();

        long startMilliseconds = System.currentTimeMillis();
        prevMilliseconds = startMilliseconds;
        lightI = 0;

        lightsChanger = new Service() {
            @Override
            protected Task createTask() {
                return new Task() {
                    @Override
                    protected Void call() throws Exception {
                        changeLights(group, startMilliseconds, System.currentTimeMillis());
                        Thread.sleep(250);
                        return null;
                    }
                };
            }
        };

        lightsChanger.start();
        lightsChanger.setOnSucceeded(new EventHandler<WorkerStateEvent>() {
            @Override
            public void handle(WorkerStateEvent workerStateEvent) {
                if (lightI == 3) {
                    lightI = 0;
                }
                lightsChanger.reset();
                lightsChanger.start();
            }
        });
    }

    public static void main(String[] args) {
        launch(args);
    }

    private static void changeLights(Group group, long startMilliseconds, long currMilliseconds) {
        {
            TrafficLightTst.TrafficLight[] trafficLights = TrafficLightTst.TrafficLight.values();

            if (currMilliseconds - prevMilliseconds <= trafficLights[lightI].getDuration()) {
                changeLight(group, trafficLights[lightI].name(), lightI);
                currMilliseconds = System.currentTimeMillis();
                if (currMilliseconds - startMilliseconds >= 90000)
                    System.exit(0);
            } else {
                changeLight(group, "grey", lightI);
                prevMilliseconds = currMilliseconds;
                lightI++;
            }

        }
    }

    private static void changeLight(Group group, String color, int index) {
        if (group.getChildren().get(index).getClass() == Circle.class)
            group.getChildren().get(index)
                    .setStyle(
                            String.format("-fx-fill: %s", color));
    }

    private static void setup(Group group, double width) {
        double centerX = width / 2;
        double start = CIRCLE_RADIUS + 100;
        for (int i = 0; i < 3; i++) {
            addCircle(group, centerX, start);
            start += CIRCLE_MARGIN + CIRCLE_RADIUS * 2;
        }
    }

    private static void addCircle(Group group, double xCoord, double yCoord) {
        Circle c = new Circle(xCoord, yCoord, CIRCLE_RADIUS);
        c.setStyle("-fx-fill: grey");
        group.getChildren().add(c);
    }
}