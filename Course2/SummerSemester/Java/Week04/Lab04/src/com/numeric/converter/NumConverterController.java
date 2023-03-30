package com.numeric.converter;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.scene.control.TextFormatter;
import javafx.scene.input.InputMethodEvent;
import javafx.scene.input.KeyEvent;
import javafx.util.converter.IntegerStringConverter;

import java.net.URL;
import java.util.ResourceBundle;
import java.util.function.UnaryOperator;

public class NumConverterController {


    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextField txtBinary;

    @FXML
    private TextField txtDecimal;

    @FXML
    private TextField txtHex;

    @FXML
    void convertDecimal(ActionEvent event) {
        convertDec();
    }

    @FXML
    void convertDecimalOnChange(KeyEvent event) {
        convertDec();
    }

    private void convertDec() {
        if (txtDecimal.getText().isBlank()) {
            return;
        }
        int value = Integer.parseInt(txtDecimal.getText());
        txtHex.setText(Integer.toHexString(value));
        txtBinary.setText(Integer.toBinaryString(value));
    }

    @FXML
    void convertHex(ActionEvent event) {
        convertHex();
    }

    @FXML
    void convertHexOnChange(KeyEvent event) {
        if (txtHex.getText().isBlank()) {
            return;
        }
    }

    private void convertHex() {
        if (txtHex.getText().isBlank()) {
            return;
        }
        int value = Integer.parseInt(txtHex.getText(), 16);
        txtBinary.setText(Integer.toBinaryString(value));
        txtDecimal.setText(Integer.toString(value));
    }

    @FXML
    void convertBinary(ActionEvent event) {
        convertBin();
    }

    @FXML
    void convertBinaryOnChange(KeyEvent event) {
        convertBin();
    }

    private void convertBin() {
        if (txtBinary.getText().isBlank()) {
            return;
        }
        int value = Integer.parseInt(txtBinary.getText(), 2);
        txtHex.setText(Integer.toHexString(value));
        txtDecimal.setText(Integer.toString(value));
    }

    @FXML
    void quit(ActionEvent event) {
        Platform.exit();
        System.exit(0);
    }

    @FXML
    void initialize() {
        assert txtBinary != null : "fx:id=\"txtBinary\" was not injected: check your FXML file 'NumConverterScene.fxml'.";
        assert txtDecimal != null : "fx:id=\"txtDecimal\" was not injected: check your FXML file 'NumConverterScene.fxml'.";
        assert txtHex != null : "fx:id=\"txtHex\" was not injected: check your FXML file 'NumConverterScene.fxml'.";

        UnaryOperator<TextFormatter.Change> integerFilter = change -> {
            String newText = change.getText();
            if (newText.matches("[0-9]*")) {
                return change;
            }
            return null;
        };

        txtDecimal.setTextFormatter(
                new TextFormatter<Integer>(new IntegerStringConverter(), 0, integerFilter));

//        UnaryOperator<TextFormatter.Change> binaryFilter = change -> {
//            String newText = change.getControlNewText();
//            if (newText.matches("[0-1]*")) {
//                return change;
//            }
//            return null;
//        };
//
//        txtBinary.setTextFormatter(
//                new TextFormatter<Integer>(new IntegerStringConverter(), 0, binaryFilter));


        UnaryOperator<TextFormatter.Change> hexFilter = change -> {
            String newText = change.getText();
            if (newText.matches("[0-9a-f]*")) {
                return change;
            }
            return null;
        };

        txtHex.setTextFormatter(
                new TextFormatter<String>(hexFilter));
        txtHex.setText("0");
    }


}
