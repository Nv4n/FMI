package Task07;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.Objects;

public class Main extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        FXMLLoader loader = new FXMLLoader(Objects.requireNonNull(getClass().getResource("BGProcessScene.fxml")));
        Parent root
                = loader.load();

        Scene scene = new Scene(root);
        Controller controller = (Controller) loader.getController();
        stage.setOnCloseRequest(e -> {
            controller.shutdown();
            Platform.exit();
            System.exit(0);
        });
        // Set the Window title
        stage.setTitle("Background process");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }
}