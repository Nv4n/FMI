package Lab13.Zad3;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class ClockPaneApp extends Application {

    @Override
    public void start(Stage primaryStage) {

        ClockPane root = new ClockPane();

        Scene scene = new Scene(root, 300, 250);

        primaryStage.setTitle("Clock!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
