package Lab13.Zad3.withThread;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;


public class ClockAnimationsWithThreadApp extends Application {


    public void start(Stage primaryStage) {
        ClockAnimationsWithThread root = new ClockAnimationsWithThread();

        Scene scene = new Scene(root, 300, 250);

        primaryStage.setTitle("Clock animation using thread!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

}
