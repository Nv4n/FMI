package Lab13.Zad2;

import javafx.application.Application;
import javafx.beans.binding.Bindings;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.scene.Scene;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class TitleBinding extends Application {

    public void start(Stage primaryStage) {
        Pane root = new Pane();
        StringProperty other = new SimpleStringProperty();

        Scene scene = new Scene(root, 300, 250);

        primaryStage.setTitle("Some title");
        primaryStage.titleProperty().bind(Bindings.concat("Title: ").concat(other));
        String v = new TextInputDialog("Enter a new title").showAndWait().orElse("Invalid title");
        other.setValue(v);// change in other, changes titleProperty value
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

}
