package com.zad3.insertion.sort;

import java.net.URL;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;

public class SortArrayController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextArea txaSortedArr;

    @FXML
    private TextArea txaUnsortedArr;

    @FXML
    private TextField txtAscendingOrder;

    @FXML
    void quit(ActionEvent event) {
        Platform.exit();
        System.exit(0);
    }

    @FXML
    void sort(ActionEvent event) {
        if (txaUnsortedArr.getText().isBlank()) {
            new Alert(Alert.AlertType.WARNING, "Empty array!").showAndWait();
            return;
        }
        if (!txaUnsortedArr.getText().matches("(\\d+\\s*)+")) {
            new Alert(Alert.AlertType.WARNING, "Invalid array format").showAndWait();
            return;
        }
        if (txtAscendingOrder.getText().isBlank()) {
            new Alert(Alert.AlertType.WARNING, "Asc input is empty").showAndWait();
            return;
        }
        if (!txtAscendingOrder.getText().matches("[YyNn]")) {
            new Alert(Alert.AlertType.WARNING, "Invalid asc input enter only 'Y/y' or 'N/n'").showAndWait();
            return;
        }

        boolean ascOrder = txtAscendingOrder.getText().matches("[Yy]");
        Integer[] numArr = Arrays.stream(txaUnsortedArr.getText().split("\\s+"))
                .mapToInt(Integer::parseInt).boxed().toArray(Integer[]::new);
        if (ascOrder) Arrays.sort(numArr);
        else Arrays.sort(numArr, Collections.reverseOrder());

        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < numArr.length; i++)
            sb.append(String.format("%d%s",
                    numArr[i],
                    i < numArr.length - 1 ? ", " : ""));
        sb.append("]");
        txaSortedArr.setText(sb.toString());
    }

    @FXML
    void initialize() {
        assert txaSortedArr != null : "fx:id=\"txaSortedArr\" was not injected: check your FXML file 'InsertionSortScene.fxml'.";
        assert txaUnsortedArr != null : "fx:id=\"txaUnsortedArr\" was not injected: check your FXML file 'InsertionSortScene.fxml'.";
        assert txtAscendingOrder != null : "fx:id=\"txtAscendingOrder\" was not injected: check your FXML file 'InsertionSortScene.fxml'.";

    }

}
