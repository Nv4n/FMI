module com.zad_three {
    requires javafx.fxml;
    requires javafx.graphics;
    requires javafx.controls;

    opens app to javafx.fxml;
    exports app to javafx.graphics;
}