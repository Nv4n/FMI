package Zad2;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.stage.Stage;

import java.util.Objects;

public class Main extends Application {

    public TextField bgnTxtField;
    public TextField interestTxtField;
    public ToggleGroup currencyToggleGroup;

    @Override
    public void start(Stage stage) throws Exception {
        Parent data = FXMLLoader.load(
                Objects.requireNonNull(getClass().getResource("main.fxml")));

        Scene scene = new Scene(data);

        // Set the Window title
        stage.setTitle("");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    //Calculate the interest in chosen currency in 10 years
    public void calculateInterest(ActionEvent actionEvent) {
        if (!validateInputs()) return;

        double value = Double.parseDouble(bgnTxtField.getText());
        int interest = Integer.parseInt(interestTxtField.getText());
        String currencyChoice =
                ((RadioButton) currencyToggleGroup.getSelectedToggle()).getText();

        if (currencyChoice.equals("EUR"))
            value *= 0.51;
        else
            value *= 0.53;

        double result = value;
        for (int i = 0; i < 10; i++)
            result = result + (result * interest / 100);


        String content = String.format("""
                Start value: %1$.2f %2$s
                Interest: %4$d%%
                Value after 10 years: %3$.2f %2$s
                """, value, currencyChoice, result, interest);

        Alert alert = new Alert(Alert.AlertType.INFORMATION, content);
        alert.setHeaderText("Statistics results");
        alert.setTitle("Calculate interest");
        alert.show();
    }

    public void quitApp(ActionEvent actionEvent) {
        Platform.exit();
    }

    private boolean validateInputs() {
        if (!bgnTxtField.getText().matches("^\\d+(\\.\\d{1,2})?$")) {
            new Alert(Alert.AlertType.ERROR, "BGN amount must be a number").show();
            return false;
        }

        if (!interestTxtField.getText().matches("^\\d+$")) {
            new Alert(Alert.AlertType.ERROR, "Interest must be a number").show();
            return false;
        }

        return true;
    }
}