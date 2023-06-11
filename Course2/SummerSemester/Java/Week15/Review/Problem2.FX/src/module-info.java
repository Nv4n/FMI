module Problem2.FX {
    requires javafx.graphics;
    requires javafx.fxml;
    requires javafx.controls;
    requires Problem2.Model;
    opens app to javafx.fxml;
    exports app to javafx.graphics;
}