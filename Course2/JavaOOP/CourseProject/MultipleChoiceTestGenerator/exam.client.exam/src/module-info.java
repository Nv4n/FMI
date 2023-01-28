module exam.client.exam {
    requires javafx.fxml;
    requires javafx.graphics;
    requires javafx.controls;
    requires questions.bank;
    requires java.rmi;
    requires exam.remote.generator;

    opens client.app to javafx.fxml;
    exports client.app to javafx.graphics;
}