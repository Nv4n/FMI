module questions.editor {
    requires javafx.fxml;
    requires javafx.graphics;
    requires javafx.controls;
    requires questions.bank;

    opens app to javafx.fxml;
    exports app to javafx.graphics;
}