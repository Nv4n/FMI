package Zad1;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.util.Arrays;
import java.util.Objects;

public class Main extends Application {

    public TextField txtSequenceSize;
    public TextField txtSequenceSeed;

    @Override
    public void start(Stage stage) throws Exception {
//        FlowPane pane = new FlowPane(14, 14);
        Parent data = FXMLLoader.load((
                Objects.requireNonNull(getClass().getResource("mainScene.fxml"))));

        Scene scene = new Scene(data);
        scene.getStylesheets().add(
                Objects.requireNonNull(getClass().getResource("styles.css")).toExternalForm());


        // Set the Window title
        stage.setTitle("Generate random sequence");
        stage.sizeToScene();
//        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    public void generateRandomSequence(javafx.event.ActionEvent actionEvent) {
        if (validateTextFields()) return;
        int size = Integer.parseInt(txtSequenceSize.getText());
        int seed = Integer.parseInt(txtSequenceSeed.getText());

        Wrapper wrapper = new Wrapper(size);
        Result result = new CipherGenerator().countDistinct(
                wrapper.makeFixedRandom(),
                seed);

        Alert alert =
                new Alert(Alert.AlertType.INFORMATION, result.toString());
        alert.setTitle("Generate random subsequence from letters A-Z");
        alert.setHeaderText("Count distinct characters out of " + size);
        alert.show();
    }

    public void generateRandomSubset(ActionEvent actionEvent) {
        if (validateTextFields()) return;
        int size = Integer.parseInt(txtSequenceSize.getText());
        int seed = Integer.parseInt(txtSequenceSeed.getText());

        Wrapper wrapper = new Wrapper(size);
        Result result = new CipherGenerator().countDistinct(
                wrapper.makeFixedSelection(),
                seed);

        Alert alert =
                new Alert(Alert.AlertType.INFORMATION, result.printNode());
        alert.setTitle("Generate random subset A-Z");
        alert.setHeaderText("Count distinct characters out of " + size);
        alert.show();
    }

    public void quitApp(ActionEvent actionEvent) {
        Platform.exit();
    }

    private boolean validateTextFields() {
        if (!txtSequenceSeed.getText().matches("^\\d+$")) {
            new Alert(Alert.AlertType.ERROR, "Seed must be a number").show();
            return true;
        }

        if (!txtSequenceSize.getText().matches("^\\d+$")) {
            new Alert(Alert.AlertType.ERROR, "Size must be a number").show();
            return true;
        }

        return false;
    }
}