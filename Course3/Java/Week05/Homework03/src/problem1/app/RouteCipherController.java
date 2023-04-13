package problem1.app;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import problem1.module.RouteCipher;

import java.net.URL;
import java.util.ResourceBundle;

public class RouteCipherController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextArea txaDecrypt;

    @FXML
    private TextArea txaEncrypt;

    @FXML
    private TextField txtCipherKey;

    RouteCipher routeCipher;

    @FXML
    void decrypt(ActionEvent event) {
        if (txaDecrypt.getText().isBlank()) {
            new Alert(Alert.AlertType.WARNING, "Decrypt field is empty").showAndWait();
            return;
        }
        setCipherKey();
        txaEncrypt.setText(routeCipher.decrypt(
                txaDecrypt.getText().toUpperCase()));
    }

    @FXML
    void encrypt(ActionEvent event) {
        if (txaEncrypt.getText().isBlank()) {
            new Alert(Alert.AlertType.WARNING, "Encrypt field is empty").showAndWait();
            return;
        }
        setCipherKey();
        txaDecrypt.setText(routeCipher.encrypt(
                txaEncrypt.getText().toUpperCase()));

    }

    private void setCipherKey() {
        if (txtCipherKey.getText().isBlank()) {
            new Alert(Alert.AlertType.WARNING, "CipherKey field is empty").showAndWait();
            return;
        }

        int cipherKey = Integer.parseInt(txtCipherKey.getText());
        if (cipherKey == 0) {
            new Alert(Alert.AlertType.WARNING, "CipherKey can't be 0").showAndWait();
            return;
        }
        routeCipher.setKey(cipherKey);
    }

    @FXML
    void quit(ActionEvent event) {
        Platform.exit();
        System.exit(0);
    }

    @FXML
    void initialize() {
        assert txaDecrypt != null : "fx:id=\"txaDecrypt\" was not injected: check your FXML file 'RouteCipherScene.fxml'.";
        assert txaEncrypt != null : "fx:id=\"txaEncrypt\" was not injected: check your FXML file 'RouteCipherScene.fxml'.";
        assert txtCipherKey != null : "fx:id=\"txtCipherKey\" was not injected: check your FXML file 'RouteCipherScene.fxml'.";
        routeCipher = new RouteCipher(0);
    }

}
