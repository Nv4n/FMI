package vue;

import java.net.URL;
import java.util.Arrays;
import java.util.Random;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextArea;
import model.Animal;
import model.AnimalInstance;
import model.AnimalType;

public class ZooSurveyController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextArea txaResults;

    @FXML
    void distributionByRegions(ActionEvent event) {
        StringBuilder res = new StringBuilder();
        for (String region : Animal.REGIONS) {
            int count = 0;
            for (AnimalInstance animal : samples)
                if (region.equals(animals[animal.getAnimalKey()].getRegion()))
                    count++;
            res.append(String.format("%20s %30d%n", region, count));
        }

        txaResults.setText(res.toString());

    }

    @FXML
    void quit(ActionEvent event) {
        Platform.exit();
        System.exit(0);
    }

    @FXML
    void showAllSortedByAge(ActionEvent event) {
        for (int i = 0; i < samples.length - 1; i++)
            for (int j = 0; j < samples.length - 1 - i; j++)
                if (samples[j].getAnimalAge() > samples[j + 1].getAnimalAge()) {
                    AnimalInstance temp = samples[j];
                    samples[j] = samples[j + 1];
                    samples[j + 1] = temp;
                }
        StringBuilder res = new StringBuilder();
        for (AnimalInstance animal : samples)
            res.append(animal.toString()).append("\n");

        txaResults.setText(res.toString());
    }

    @FXML
    void showEndangeredAnimalType(ActionEvent event) {
        AnimalType[] types = AnimalType.values();
        StringBuilder res = new StringBuilder();
        for (AnimalType type : types) {
            int count = 0;
            for (AnimalInstance animalIns : samples) {
                Animal animal = animals[animalIns.getAnimalKey()];
                if (type == animal.getAnimalType()
                        && animal.isEndangered())
                    count++;
            }

            res.append(String.format("%20s %30d%n", type.name(), count));
        }

        txaResults.setText(res.toString());

    }

    @FXML
    void shuffleSamples(ActionEvent event) {
        for (int i = samples.length - 1; i > 0; i--) {
            int ind = rand.nextInt(i + 1);
            AnimalInstance animal = samples[ind];
            samples[ind] = samples[i];
            samples[i] = animal;
        }

        StringBuilder res = new StringBuilder();
        for (AnimalInstance a : samples)
            res.append(a.toString()).append("\n");

        txaResults.setText(res.toString());
    }

    private AnimalInstance[] samples;
    private Animal[] animals;
    private Random rand;

    @FXML
    void initialize() {
        assert txaResults != null : "fx:id=\"txaResults\" was not injected: check your FXML file 'ZooSurveyScene.fxml'.";
        animals = new Animal[]{
                new Animal("Тигър", AnimalType.MAMMAL, true, "Asia", true),
                new Animal("Фламинго", AnimalType.BIRD, false, "Africa", true),
                new Animal("Гущер", AnimalType.REPTILE, true, "Australia", true),
                new Animal("Пъстърва", AnimalType.FISH, false, "Europe", false),
                new Animal("Делфин", AnimalType.MAMMAL, false, "Australia", true),
                new Animal("Вълк", AnimalType.MAMMAL, true, "America", false)
        };

        samples = new AnimalInstance[20];
        rand = new Random();
        for (int i = 0; i < samples.length; i++) {
            int key = rand.nextInt(0, animals.length);
            int age = rand.nextInt(9, 30) + 1;
            samples[i] = new AnimalInstance(key, animals[key].getName(), age);
        }
    }

}
