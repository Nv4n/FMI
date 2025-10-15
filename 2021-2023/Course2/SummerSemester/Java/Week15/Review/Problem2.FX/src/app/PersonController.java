package app;

import java.net.URL;
import java.time.LocalDate;
import java.time.Period;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.text.Text;
import model.Person;

import java.time.LocalDate;

public class PersonController {
    List<Person> personList;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private ComboBox<String> cmbPeople;

    @FXML
    private Text txtFname;

    @FXML
    private Text txtHiredAt;

    @FXML
    private Text txtLname;

    @FXML
    private Text txtYearsAtWork;

    @FXML
    private void onPersonChange(ActionEvent event) {
        Person person = personList.get(cmbPeople.getSelectionModel().getSelectedIndex());
        txtFname.setText(person.getFirstName());
        txtLname.setText(person.getLastName());
        Period years = Period.between(person.getHireDate(), LocalDate.now());
        txtHiredAt.setText(person.getHireDate().toString());
        txtYearsAtWork.setText(Integer.toString(years.getYears()));
    }

    @FXML
    void initialize() {
        assert cmbPeople != null : "fx:id=\"cmbPeople\" was not injected: check your FXML file 'PersoScene.fxml'.";
        assert txtFname != null : "fx:id=\"txtFname\" was not injected: check your FXML file 'PersoScene.fxml'.";
        assert txtHiredAt != null : "fx:id=\"txtHiredAt\" was not injected: check your FXML file 'PersoScene.fxml'.";
        assert txtLname != null : "fx:id=\"txtLname\" was not injected: check your FXML file 'PersoScene.fxml'.";
        assert txtYearsAtWork != null : "fx:id=\"txtYearsAtWork\" was not injected: check your FXML file 'PersoScene.fxml'.";
        personList = new ArrayList<>(List.of(new Person[]{
                new Person("George", "Georgiev", LocalDate.of(2014, 8, 4)),
                new Person("Pavel", "Ivanov", LocalDate.of(2012, 1, 14)),
                new Person("Ivan", "Petrov", LocalDate.of(2019, 5, 12)),
                new Person("Stoyan", "Pavlov", LocalDate.of(2018, 3, 24)),
                new Person("Kiril", "Simeonov", LocalDate.of(2020, 7, 4)),
                new Person("Jordan", "Angelov", LocalDate.of(2017, 2, 6))
        }));
        List<String> names = personList.stream()
                .map(s -> String.format("%s, %s", s.getFirstName(), s.getLastName()))
                .toList();
        cmbPeople.getItems().addAll(FXCollections.observableList(names));
    }

}
