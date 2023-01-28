package remote.app;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.scene.control.TextFormatter;
import javafx.util.converter.IntegerStringConverter;
import obj.questions.app.QuestionSerializer;
import obj.questions.obj.Question;

import java.io.IOException;
import java.net.URL;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.List;
import java.util.ResourceBundle;
import java.util.function.UnaryOperator;

public class ExamGeneratorController {
    private Exam exam;
    private Registry registry;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextField examDurationTxt;

    @FXML
    private TextField questionCountTxt;

    @FXML
    void getQuestions(ActionEvent event) {
        try {
            List<Question> array = QuestionSerializer.deserializeFromXML();
            exam.setQuestions(array);
        } catch (IOException e) {
            new Alert(Alert.AlertType.WARNING, "Couldn't get the questions").showAndWait();
        }
    }

    @FXML
    void updateExamSettings(ActionEvent event) {
        try {
            if (exam.getQuestions() == null) {
                new Alert(Alert.AlertType.INFORMATION, "You need to get the questions first").showAndWait();
                return;
            }
            exam.setExamDuration(Integer.parseInt(examDurationTxt.getText()));
            try {
                exam.setQuestionsCount(Integer.parseInt(questionCountTxt.getText()));
            } catch (RuntimeException e) {
                new Alert(Alert.AlertType.INFORMATION, e.getMessage()).showAndWait();
                return;
            }

            String remoteObjName = "Exam";
            try {
                if (registry == null) registry = LocateRegistry.createRegistry(1099);

                registry.rebind(remoteObjName, exam);
                System.out.printf("Remote object named: %s is registered. Registry is running ...%n", remoteObjName);
                System.out.println(exam.toString());
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    @FXML
    void initialize() {
        assert examDurationTxt != null : "fx:id=\"examMinsTxt\" was not injected: check your FXML file 'ExamGeneratorScene.fxml'.";
        assert questionCountTxt != null : "fx:id=\"questionCountTxt\" was not injected: check your FXML file 'ExamGeneratorScene.fxml'.";

        UnaryOperator<TextFormatter.Change> integerFilter = change -> {
            String newText = change.getControlNewText();
            if (newText.matches("([1-9][0-9]*)?")) return change;
            return null;
        };

        examDurationTxt.setTextFormatter(
                new TextFormatter<Integer>(new IntegerStringConverter(), 1, integerFilter));
        questionCountTxt.setTextFormatter(
                new TextFormatter<Integer>(new IntegerStringConverter(), 1, integerFilter));
        try {
            exam = new Exam();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

}
