module TestExam {
    requires javafx.fxml;
    requires javafx.graphics;

    opens exam to javafx.fxml;
    exports exam to javafx.graphics;
}