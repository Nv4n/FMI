package app;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.util.StringConverter;
import javafx.util.converter.NumberStringConverter;

public class BindController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Slider sliderValue;

    @FXML
    private TextField txtFractionValue;

    @FXML
    private TextField txtGoodNumberValue;

    @FXML
    private TextField txtValue;

    @FXML
    void initialize() {
        assert sliderValue != null : "fx:id=\"sliderValue\" was not injected: check your FXML file 'BindScene.fxml'.";
        assert txtFractionValue != null : "fx:id=\"txtFractionValue\" was not injected: check your FXML file 'BindScene.fxml'.";
        assert txtGoodNumberValue != null : "fx:id=\"txtGoodNumberValue\" was not injected: check your FXML file 'BindScene.fxml'.";
        assert txtValue != null : "fx:id=\"txtValue\" was not injected: check your FXML file 'BindScene.fxml'.";

        StringConverter<Number> converter = new NumberStringConverter();
        var roundValueConverter = new StringConverter<Number>() {
            @Override
            public String toString(Number number) {
                return Integer.toString(number.intValue());
            }

            @Override
            public Number fromString(String s) {
                return Double.parseDouble(s);
            }
        };
        var noRoundValueConverter = new StringConverter<Number>() {
            private String phrase = "Value: ";

            @Override
            public String toString(Number number) {
                return String.format("%s%06.1f", phrase, Double.parseDouble(number.toString()));
            }

            @Override
            public Number fromString(String s) {
                String res = s.replace(phrase, "");
                System.out.println(res);
                return Double.parseDouble(res);
            }
        };
        var goodNumberValueConverter = new StringConverter<Number>() {
            private String phrase = " is a good number";

            @Override
            public String toString(Number number) {
                return String.format("%.1f%s", Double.parseDouble(number.toString()), phrase);
            }

            @Override
            public Number fromString(String s) {
                String res = s.replace(phrase, "");
                System.out.println(res);
                return Double.parseDouble(res);
            }
        };

        txtValue.textProperty().bindBidirectional(sliderValue.valueProperty(), roundValueConverter);
        txtFractionValue.textProperty().bindBidirectional(sliderValue.valueProperty(), noRoundValueConverter);
        txtGoodNumberValue.textProperty().bindBidirectional(sliderValue.valueProperty(), goodNumberValueConverter);
    }

}
