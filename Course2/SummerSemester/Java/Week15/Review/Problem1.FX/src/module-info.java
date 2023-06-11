module FX {
    requires javafx.fxml;
    requires javafx.controls;
    requires javafx.graphics;
    requires Model;
    opens app to javafx.fxml;
    exports app to javafx.graphics;
}