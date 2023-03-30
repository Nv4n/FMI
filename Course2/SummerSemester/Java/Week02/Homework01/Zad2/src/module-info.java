module Zad2 {
    requires javafx.graphics;
    requires javafx.fxml;
    opens com.problem2 to javafx.fxml;
    exports com.problem2 to javafx.graphics;
}