module exam.remote.generator {
    requires javafx.fxml;
    requires javafx.graphics;
    requires java.rmi;
    requires questions.bank;
    requires javafx.controls;
    requires java.desktop;
    requires org.jetbrains.annotations;

    opens remote.app to javafx.fxml;
    exports remote.app to javafx.graphics;
    opens remote.obj to java.rmi;
    exports remote.obj;
}