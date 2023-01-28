module exam.remote.generator {
    requires javafx.fxml;
    requires javafx.graphics;
    requires java.rmi;
    requires questions.bank;
    requires javafx.controls;
    requires java.desktop;
    requires org.jetbrains.annotations;

    opens app to javafx.fxml;
    exports app to javafx.graphics;
    opens obj to java.rmi;
    exports obj;
}