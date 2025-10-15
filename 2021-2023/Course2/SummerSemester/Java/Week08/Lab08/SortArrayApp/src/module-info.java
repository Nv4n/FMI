module SortArrayApp {
    requires javafx.fxml;
    requires javafx.controls;
    requires javafx.graphics;

    opens com.zad3.insertion.sort to javafx.fxml;
    exports com.zad3.insertion.sort to javafx.graphics;
}