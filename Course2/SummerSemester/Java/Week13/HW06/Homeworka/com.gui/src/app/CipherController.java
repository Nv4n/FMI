package app;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.scene.control.TextFormatter;
import model.CipherGenerator;
import model.Result;
import model.Wrapper;

import java.net.URL;
import java.util.ResourceBundle;

public class CipherController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextField txtSeed;

    @FXML
    private TextField txtSize;

    @FXML
    void generateSubset(ActionEvent event) {
        if (txtSeed.getText().isBlank()) {
            new Alert(Alert.AlertType.ERROR, "Seed can't be empty").showAndWait();
            return;
        }
        if (txtSize.getText().isBlank()) {
            new Alert(Alert.AlertType.ERROR, "Size can't be empty").showAndWait();
            return;
        }
        int size = Integer.parseInt(txtSize.getText());
        int seed = Integer.parseInt(txtSeed.getText());
        Wrapper wrapper = new Wrapper(size);

        Result result = CipherGenerator.countDistinct(wrapper.makeFixedSelection(), seed);

        new Alert(Alert.AlertType.INFORMATION,
                String.format("Chars: [%s]%nResult: %d"
                        , String.join(", ", String.valueOf(result.getChars()).split("")),
                        result.getData())).showAndWait();
    }

    @FXML
    void generateRandom(ActionEvent event) {
        if (txtSeed.getText().isBlank()) {
            new Alert(Alert.AlertType.ERROR, "Seed can't be empty").showAndWait();
            return;
        }
        if (txtSize.getText().isBlank()) {
            new Alert(Alert.AlertType.ERROR, "Size can't be empty").showAndWait();
            return;
        }
        int size = Integer.parseInt(txtSize.getText());
        int seed = Integer.parseInt(txtSeed.getText());
        Wrapper wrapper = new Wrapper(size);

        Result result = CipherGenerator.countDistinct(wrapper.makeFixedRandom(), seed);

        new Alert(Alert.AlertType.INFORMATION,
                String.format("Chars: [%s]%nResult: %d"
                        , String.join(", ", String.valueOf(result.getChars()).split("")),
                        result.getData())).showAndWait();
    }

    @FXML
    void quit(ActionEvent event) {
        Platform.exit();
        System.exit(0);
    }

    @FXML
    void initialize() {
        assert txtSeed != null : "fx:id=\"txtSeed\" was not injected: check your FXML file 'CipherScene.fxml'.";
        assert txtSize != null : "fx:id=\"txtSize\" was not injected: check your FXML file 'CipherScene.fxml'.";
        txtSeed.setTextFormatter(new TextFormatter<>(change -> {
            String newText = change.getControlNewText();
            if (newText.matches("([1-9][0-9]*|0|)")) return change;
            return null;
        }));
        txtSize.setTextFormatter(new TextFormatter<>(change -> {
            String newText = change.getControlNewText();
            if (newText.matches("([1-9][0-9]*|0|)")) return change;
            return null;
        }));
    }
}
