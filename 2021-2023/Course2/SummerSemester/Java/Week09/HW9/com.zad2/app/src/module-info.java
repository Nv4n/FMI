module com.zad_two.app {
    requires javafx.fxml;
    requires javafx.graphics;
    requires javafx.controls;
    requires Calculator;
    opens app to javafx.fxml;
    exports app to javafx.graphics;
}