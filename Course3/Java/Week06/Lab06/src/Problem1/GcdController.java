package Problem1;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

public class GcdController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextField txtA;

    @FXML
    private TextField txtB;

    @FXML
    private TextField txtGCD;

    @FXML
    void computeGCD(ActionEvent event) {
        if (txtA.getText().isBlank() || txtB.getText().isBlank()) {
            new Alert(Alert.AlertType.WARNING, "There are empty fields").showAndWait();
            return;
        }

        int a = Integer.parseInt(txtA.getText());
        int b = Integer.parseInt(txtB.getText());
        int gcd = computeGCD(Math.max(a, b), Math.min(a, b));
        txtGCD.setText(Integer.toString(gcd));
    }

    int computeGCD(int a, int b) {
        if (a % b == 0) return b;
        return computeGCD(b, a % b);
    }

    @FXML
    void quit(ActionEvent event) {
        Platform.exit();
        System.exit(0);
    }

    @FXML
    void initialize() {
        assert txtA != null : "fx:id=\"txtA\" was not injected: check your FXML file 'GcdScene.fxml'.";
        assert txtB != null : "fx:id=\"txtB\" was not injected: check your FXML file 'GcdScene.fxml'.";
        assert txtGCD != null : "fx:id=\"txtGCD\" was not injected: check your FXML file 'GcdScene.fxml'.";

    }

}
