module com.gui {
//    requires javafx.
    requires javafx.controls;
    requires javafx.graphics;
    requires javafx.fxml;
    requires com.providers;
    requires com.services;
    opens app to javafx.fxml;
    exports app to javafx.graphics;
}