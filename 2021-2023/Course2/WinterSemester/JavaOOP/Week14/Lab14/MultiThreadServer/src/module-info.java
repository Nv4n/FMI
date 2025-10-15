module MultiThreadServer {
    requires javafx.fxml;
    requires javafx.graphics;
    requires javafx.controls;

    opens server to javafx.fxml;
    opens client to javafx.fxml;

    exports server to javafx.graphics;
    exports client to javafx.graphics;
}
