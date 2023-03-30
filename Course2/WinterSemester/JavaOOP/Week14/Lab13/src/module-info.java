module Lab13 {
    requires javafx.controls;
    requires javafx.fxml;
    opens Lab13.Zad2 to javafx.fxml;
    opens Lab13.Zad3 to javafx.fxml;

    opens Lab13.Zad3.withThread to javafx.fxml;
    exports Lab13.Zad3.withThread to javafx.graphics;

    exports Lab13.Zad2 to javafx.graphics;
    exports Lab13.Zad3 to javafx.graphics;
}