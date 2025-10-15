package Problem1;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.Objects;

public class GcdApp extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        Parent root
                = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("GcdScene.fxml")));

        Scene scene = new Scene(root);

        // Set the Window title
        stage.setTitle("GCD");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}