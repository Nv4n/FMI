package com.controller;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class FormController {
    @FXML
    private Label lblUsername;
    @FXML
    private Label lblConfirmPassword;
    @FXML
    private Label lblEmail;
    @FXML
    private Label lblPhoneNumber;
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

    public void registerUser(ActionEvent actionEvent) {
        resetLabels();
        if (areFieldsInvalid()) return;

        new Alert(Alert.AlertType.INFORMATION, "User is registered").showAndWait();
        txtUsername.setText("");
        txtPhoneNumber.setText("");
        txtEmail.setText("");
        txtPassword.setText("");
        txtRePassword.setText("");
    }

    private void resetLabels() {
        lblUsername.setText("");
        lblPhoneNumber.setText("");
        lblEmail.setText("");
        lblConfirmPassword.setText("");
    }

    private boolean areFieldsInvalid() {
        boolean flag = false;
        if (!txtUsername.getText().trim().matches("^[a-z]{2,}$") || txtUsername.getText().isBlank()) {
            lblUsername.setText("Invalid username");
            flag = true;
        }
        if (!txtPhoneNumber.getText().trim().matches("^\\(\\d{4}\\) \\(\\d{7}\\)$")
                || txtPhoneNumber.getText().isBlank()) {
            lblPhoneNumber.setText("Invalid phone number");
            flag = true;
        }
        if (txtEmail.getText().trim().matches(" |@.*@|\\..*\\.")
                || txtEmail.getText().isBlank()) {
            lblEmail.setText("Invalid email");
            flag = true;
        }
        if (!txtPassword.getText().trim().matches(txtRePassword.getText().trim())
                || txtPassword.getText().isBlank() || txtRePassword.getText().isBlank()) {
            lblConfirmPassword.setText("Passwords Are Not Identical");
            flag = true;
        }
        return flag;
    }
}
