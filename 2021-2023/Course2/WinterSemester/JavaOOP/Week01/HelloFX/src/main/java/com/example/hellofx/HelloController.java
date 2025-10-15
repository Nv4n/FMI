package com.example.hellofx;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

import java.util.Timer;

public class HelloController {
    @FXML
    private Label welcomeText;

    @FXML
    protected void onHelloButtonClick() {
        welcomeText.setText("Welcome to JavaFX Application!");
    }
}