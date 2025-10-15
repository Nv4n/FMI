module Problem4.FX {
    requires javafx.graphics;
    requires javafx.fxml;
    requires javafx.controls;
    opens app to javafx.fxml;
    exports app to javafx.graphics;
}