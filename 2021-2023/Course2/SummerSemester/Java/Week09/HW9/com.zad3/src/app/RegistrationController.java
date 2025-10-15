package app;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

public class RegistrationController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextField txtEmail;

    @FXML
    private TextField txtName;

    @FXML
    private TextField txtPassword;

    @FXML
    private TextField txtPhone;

    @FXML
    private TextField txtRePassword;

    @FXML
    void quit(ActionEvent event) {
        Platform.exit();
        System.exit(0);
    }

    @FXML
    void register(ActionEvent event) {
        if (txtName.getText().isBlank()
                || txtPhone.getText().isBlank()
                || txtEmail.getText().isBlank()
                || txtPassword.getText().isBlank()
                || txtRePassword.getText().isBlank()) {
            new Alert(Alert.AlertType.WARNING, "Don't leave the fields empty!").showAndWait();
            return;
        }

        if (!txtName.getText().matches("([A-Z][a-z]+|[a-z]{2,})")) {
            new Alert(Alert.AlertType.WARNING, "Name doesn't match format").showAndWait();
            return;
        }

        if (!txtPhone.getText().matches("\\(\\d{4}\\) \\(\\d{7}\\)")) {
            new Alert(Alert.AlertType.WARNING, "Phone number doesn't match format").showAndWait();
            return;
        }

        if (!txtEmail.getText().matches("(\\w+\\.?)+[^\\s@]@[^\\s@](\\w+\\.?)+")) {
            new Alert(Alert.AlertType.WARNING, "Email doesn't match format").showAndWait();
            return;
        }

        if (!txtRePassword.getText().equals(txtPassword.getText())) {
            new Alert(Alert.AlertType.WARNING, "Passwords are not identical").showAndWait();
            return;
        }

        new Alert(Alert.AlertType.INFORMATION, "YOU ARE REGISTERED").showAndWait();
    }

    @FXML
    void initialize() {
        assert txtEmail != null : "fx:id=\"txtEmail\" was not injected: check your FXML file 'RegistrationScene.fxml'.";
        assert txtName != null : "fx:id=\"txtName\" was not injected: check your FXML file 'RegistrationScene.fxml'.";
        assert txtPassword != null : "fx:id=\"txtPassword\" was not injected: check your FXML file 'RegistrationScene.fxml'.";
        assert txtPhone != null : "fx:id=\"txtPhone\" was not injected: check your FXML file 'RegistrationScene.fxml'.";
        assert txtRePassword != null : "fx:id=\"txtRePassword\" was not injected: check your FXML file 'RegistrationScene.fxml'.";

    }

}
