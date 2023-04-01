package Problem2;

import java.net.URL;
import java.sql.Array;
import java.util.Arrays;
import java.util.ResourceBundle;
import java.util.Stack;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

public class PermutationsController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextArea txaPermutations;

    @FXML
    private TextField txtArray;

    @FXML
    void computePermutations(ActionEvent event) {
        if (txtArray.getText().isBlank()) {
            new Alert(Alert.AlertType.WARNING, "No input was provided").showAndWait();
            return;
        }

        String[] digits = txtArray.getText()
                .replaceAll("[\\[\\]]", "")
                .split(", ");

        computePermutations(digits, 0);
    }

    private void computePermutations(String[] digits, int i) {
        System.out.println("Not implemented");
    }

    @FXML
    void quit(ActionEvent event) {
        Platform.exit();
        System.exit(0);
    }

    @FXML
    void initialize() {
        assert txaPermutations != null : "fx:id=\"txaPermutations\" was not injected: check your FXML file 'PermutationsScene.fxml'.";
        assert txtArray != null : "fx:id=\"txtArray\" was not injected: check your FXML file 'PermutationsScene.fxml'.";

    }

}
