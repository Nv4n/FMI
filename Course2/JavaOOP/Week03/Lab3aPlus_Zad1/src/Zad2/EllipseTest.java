package Zad2;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextInputDialog;
import javafx.stage.Stage;

import java.util.Scanner;

public class EllipseTest extends Application {

    @Override
    public void start(Stage stage) throws Exception {
        Group group = new Group();

        Scene scene = new Scene(group, 500, 500);
        drawEllipse(group, stage.getWidth(), stage.getHeight());
        // Set the Window title
        stage.setTitle("EllipseTest");
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    private static void drawEllipse(Group group, double width, double height) {
        TextInputDialog inputDialog = new TextInputDialog();
        inputDialog.setHeaderText("Input the bix axis");
        inputDialog.setContentText("Value: ");
        inputDialog.showAndWait();
        double a = Double.parseDouble(inputDialog.getResult());
        inputDialog.setHeaderText("Input the small axis");
        inputDialog.showAndWait();
        double b = Double.parseDouble(inputDialog.getResult());

        Ellipse ellipse = new Ellipse(a, b, width, height);
        ellipse.drawEllipse(group);
    }
}