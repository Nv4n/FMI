package com.controller;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextField;
import javafx.scene.control.TextFormatter;

import java.net.URL;
import java.util.ResourceBundle;

public class FormController implements Initializable {
    @FXML
    private TextField txtUsername;
    @FXML
    private TextField txtPhoneNumber;
    @FXML
    private TextField txtEmail;
    @FXML
    private TextField txtPassword;
    @FXML
    private TextField txtRePassword;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        txtUsername.setTextFormatter(new TextFormatter<>(change -> {
            String newText = change.getControlNewText().trim();
            if (!newText.matches("^[a-z]{2,}$")) {
                change.setText(newText.replaceAll("[^a-z]+", ""));
            }
            return change;
        }));
    }
}
