package app;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextField;
import obj.questions.app.QuestionSerializer;
import obj.questions.obj.Question;
import obj.questions.obj.QuestionOption;

import java.io.IOException;
import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

/**
 * Едитор, с който можем да добавяме нови въпроси
 */
public class EditorController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button addQuestionBtn;

    @FXML
    private ChoiceBox<String> answerCmb;

    @FXML
    private TextField fieldATxt;

    @FXML
    private TextField fieldBTxt;

    @FXML
    private TextField fieldCTxt;

    @FXML
    private TextField fieldDTxt;

    @FXML
    private TextField questionTxt;

    /**
     * Инициализира първоначалния изглед
     */
    @FXML
    void initialize() {
        assert addQuestionBtn != null : "fx:id=\"addQuestionBtn\" was not injected: check your FXML file 'EditorScene.fxml'.";
        assert answerCmb != null : "fx:id=\"answerCmb\" was not injected: check your FXML file 'EditorScene.fxml'.";
        assert fieldATxt != null : "fx:id=\"fieldATxt\" was not injected: check your FXML file 'EditorScene.fxml'.";
        assert fieldBTxt != null : "fx:id=\"fieldBTxt\" was not injected: check your FXML file 'EditorScene.fxml'.";
        assert fieldCTxt != null : "fx:id=\"fieldCTxt\" was not injected: check your FXML file 'EditorScene.fxml'.";
        assert fieldDTxt != null : "fx:id=\"fieldDTxt\" was not injected: check your FXML file 'EditorScene.fxml'.";
        assert questionTxt != null : "fx:id=\"questionTxt\" was not injected: check your FXML file 'EditorScene.fxml'.";

        answerCmb.getItems().add("A");
        answerCmb.getItems().add("B");
        answerCmb.getItems().add("C");
        answerCmb.getItems().add("D");
        answerCmb.setValue("A");
    }

    /**
     * Добавя новия въпрос и рестартира полетата
     *
     * @param event
     * @throws IOException
     */
    @FXML
    void addQuestion(ActionEvent event) throws IOException {
        if (isFieldEmpty(questionTxt, "Question")) return;
        if (isFieldEmpty(fieldATxt, "Answer A")) return;
        if (isFieldEmpty(fieldBTxt, "Answer B")) return;
        if (isFieldEmpty(fieldCTxt, "Answer C")) return;
        if (isFieldEmpty(fieldDTxt, "Answer D")) return;

        Question newQuestion = new Question(
                questionTxt.getText(),
                fieldATxt.getText(),
                fieldBTxt.getText(),
                fieldCTxt.getText(),
                fieldDTxt.getText(),
                QuestionOption.valueOf(answerCmb.getValue()));

        List<Question> questions = QuestionSerializer.deserializeFromXML();
        questions.add(newQuestion);
        QuestionSerializer.serializeToXML(questions);
        emptyFields();
    }

    /**
     * @param field
     * @param fieldName
     * @return Връща дали полето е празно
     */
    private boolean isFieldEmpty(TextField field, String fieldName) {
        if (field.getText().isEmpty())
            new Alert(Alert.AlertType.ERROR, String.format("%s is empty", fieldName))
                    .showAndWait();
        return field.getText().isEmpty();
    }

    /**
     * Рестартира полетата до начални стойности
     */
    private void emptyFields() {
        questionTxt.setText("");
        fieldATxt.setText("");
        fieldBTxt.setText("");
        fieldCTxt.setText("");
        fieldDTxt.setText("");
        answerCmb.setValue("A");
    }
}
