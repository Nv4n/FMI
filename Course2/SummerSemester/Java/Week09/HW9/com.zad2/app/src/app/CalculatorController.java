package app;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.scene.control.TextFormatter;
import model.Calculator;
import model.Operation;

import java.net.URL;
import java.util.ResourceBundle;

public class CalculatorController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextField txtCalcInput;

    private Calculator calculator;

    private void updateMemoryIfNoMemory() {
        if (!calculator.isHasSaved() && !txtCalcInput.getText().isBlank()) {
            double value = Double.parseDouble(txtCalcInput.getText());
            calculator.setMemory(value);
            calculator.setHasSaved(true);
            txtCalcInput.clear();
        }
    }

    private void computeActionClicked(Operation operation) {
        updateMemoryIfNoMemory();

        if (!txtCalcInput.getText().isBlank()) {
            double value = Double.parseDouble(txtCalcInput.getText());
            calculator.setCurrentValue(value);
            try {
                calculator.compute();
            } catch (IllegalArgumentException err) {
                new Alert(Alert.AlertType.ERROR, err.getMessage()).showAndWait();
            }
            txtCalcInput.clear();
        }

        calculator.setOperation(operation);
    }

    private void symbolActionClicked(char symbol) {
        String curr = txtCalcInput.getText();
        txtCalcInput.setText(curr + symbol);
    }

    @FXML
    void clearInput(ActionEvent event) {
        txtCalcInput.clear();
    }

    @FXML
    void clearMemory(ActionEvent event) {
        txtCalcInput.clear();
        calculator.setHasSaved(false);
    }

    @FXML
    void divide(ActionEvent event) {
        computeActionClicked(Operation.DIVIDE);
    }

    @FXML
    void dot(ActionEvent event) {
        symbolActionClicked('.');
    }

    @FXML
    void equals(ActionEvent event) {
        computeActionClicked(Operation.UNKNOWN);
        txtCalcInput.setText(Double.toString(calculator.getMemory()));
    }

    @FXML
    void minus(ActionEvent event) {
        computeActionClicked(Operation.MINUS);
    }

    @FXML
    void multiply(ActionEvent event) {
        computeActionClicked(Operation.MULTIPLY);
    }


    @FXML
    void plus(ActionEvent event) {
        computeActionClicked(Operation.PLUS);
    }

    @FXML
    void quit(ActionEvent event) {
        Platform.exit();
        System.exit(0);
    }

    @FXML
    void typeTwoZeros(ActionEvent event) {
        symbolActionClicked('0');
        symbolActionClicked('0');
    }

    @FXML
    void typeZero(ActionEvent event) {
        symbolActionClicked('0');
    }


    @FXML
    void typeOne(ActionEvent event) {
        symbolActionClicked('1');
    }

    @FXML
    void typeTwo(ActionEvent event) {
        symbolActionClicked('2');
    }

    @FXML
    void typeThree(ActionEvent event) {
        symbolActionClicked('3');
    }

    @FXML
    void typeFour(ActionEvent event) {
        symbolActionClicked('4');
    }

    @FXML
    void typeFive(ActionEvent event) {
        symbolActionClicked('5');
    }

    @FXML
    void typeSix(ActionEvent event) {
        symbolActionClicked('6');
    }

    @FXML
    void typeSeven(ActionEvent event) {
        symbolActionClicked('7');
    }

    @FXML
    void typeEight(ActionEvent event) {
        symbolActionClicked('8');
    }


    @FXML
    void typeNine(ActionEvent event) {
        symbolActionClicked('9');
    }


    @FXML
    void initialize() {
        assert txtCalcInput != null : "fx:id=\"txtCalcInput\" was not injected: check your FXML file 'CalculatorScene.fxml'.";
        calculator = new Calculator();

        TextFormatter<Double> doubleTextFormatter = new TextFormatter<>(change -> {
            String newText = change.getControlNewText();
            if (newText.matches("(|(([1-9][0-9]*|0)(\\.|\\.[0-9]+)?))")) return change;
            else return null;

        });

        txtCalcInput.setTextFormatter(doubleTextFormatter);
    }


}
