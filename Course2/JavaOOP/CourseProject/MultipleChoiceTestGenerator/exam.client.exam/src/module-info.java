module exam.client.exam {
    requires javafx.fxml;
    requires javafx.graphics;
    requires javafx.controls;
    requires questions.bank;
    requires java.rmi;
    requires exam.remote.generator;

    opens app to javafx.fxml;
    exports app to javafx.graphics;
}