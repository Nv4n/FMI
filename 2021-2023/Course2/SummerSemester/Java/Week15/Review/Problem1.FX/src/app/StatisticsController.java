package app;

import java.lang.reflect.Array;
import java.net.URL;
import java.util.*;
import java.util.stream.Collectors;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import model.Statistics;

public class StatisticsController {
    private List<Statistics> statList;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private ComboBox<String> cmbCountries;

    @FXML
    private Label lData;


    @FXML
    void valueChange(ActionEvent event) {
        Statistics stats = statList.stream()
                .filter(s -> s.getCountry().matches(cmbCountries.getValue()))
                .findFirst().get();
        lData.setText(Integer.toString(stats.getData()));
    }

    @FXML
    void initialize() {
        assert cmbCountries != null : "fx:id=\"cmbCountries\" was not injected: check your FXML file 'StatisticsScene.fxml'.";
        assert lData != null : "fx:id=\"lData\" was not injected: check your FXML file 'StatisticsScene.fxml'.";
        statList = new ArrayList<>(List.of(new Statistics[]{
                new Statistics("Belgium", 3),
                new Statistics("France", 26),
                new Statistics("Germany", 35),
                new Statistics("Netherlands", 7),
                new Statistics("Sweden", 4),
                new Statistics("United Kingdom", 25)
        }));
        List<String> countriesList = statList.stream().map(Statistics::getCountry).toList();
        cmbCountries.getItems().addAll(FXCollections.observableList(countriesList));
        lData.setText("");
    }

}
