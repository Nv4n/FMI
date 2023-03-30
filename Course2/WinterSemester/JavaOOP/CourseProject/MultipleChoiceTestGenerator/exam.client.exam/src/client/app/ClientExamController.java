package client.app;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.*;
import obj.questions.obj.Question;
import obj.questions.obj.QuestionOption;
import remote.obj.Examinable;
import remote.obj.StudentAnswerSheet;

import java.net.URL;
import java.rmi.AccessException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Date;
import java.util.List;
import java.util.ResourceBundle;

public class ClientExamController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Label fieldATxt;

    @FXML
    private Label fieldBTxt;

    @FXML
    private Label fieldCTxt;

    @FXML
    private Label fieldDTxt;

    @FXML
    private Button goBackBtn;

    @FXML
    private Button goNextBtn;

    @FXML
    private TextField nameTxt;

    @FXML
    private Label questionTxt;

    @FXML
    private ToggleGroup selectedAnswer;

    @FXML
    private Button sendBtn;

    @FXML
    private Button startExamBtn;

    @FXML
    private Label timeTxt;

    private Examinable exam;
    private List<Question> questions;
    private int index;
    private int duration;

    private StudentAnswerSheet studentAnswerSheet;

    /**
     * Задава началните стойности за изпитния лист с отговори
     * След това зарежда първия въпрос и забранява промяната на името
     *
     * @param event
     */
    @FXML
    void startExam(ActionEvent event) {
        if (nameTxt.getText().isEmpty()) {
            new Alert(Alert.AlertType.WARNING, "Enter your name before starting").showAndWait();
            return;
        }
        Date currentDate = new Date();
        List<QuestionOption> answers = questions.stream().map(Question::getRightAnswer).toList();
        studentAnswerSheet = new StudentAnswerSheet(nameTxt.getText(), currentDate, answers);
        fillFields(questions.get(index));

        selectedAnswer.getToggles().forEach(t -> {
            Node node = (Node) t;
            node.setDisable(false);
        });

        nameTxt.setDisable(true);
        startExamBtn.setDisable(true);
        setControlExamBtns();
    }

    /**
     * Спира изпита, регистрира ученика и му връща крайната оценка
     */
    private void stop() {
        try {
            if (studentAnswerSheet == null) return;
            exam.registerStudent(studentAnswerSheet);
            List<QuestionOption> answers = studentAnswerSheet.getStudentAnswers();
            List<QuestionOption> realAnswers = studentAnswerSheet.getRealAnswers();
            int count = 0;
            for (int i = 0; i < answers.size(); i++)
                if (answers.get(i) == realAnswers.get(i))
                    count++;
            int points = count * 100 / answers.size();
            new Alert(
                    Alert.AlertType.INFORMATION,
                    String.format("Your score is: %d", getGrade(points)
                    )).showAndWait();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
        Platform.exit();
        System.exit(0);
    }

    /**
     * Ипзраща и завършва изпита
     *
     * @param event
     */
    @FXML
    void sendExam(ActionEvent event) {
        stop();
    }

    /**
     * @param points
     * @return Връща дадената оценка спрямо точките
     */
    private int getGrade(int points) {
        if (points <= 54) return 2;
        if (points <= 64) return 3;
        if (points <= 74) return 4;
        if (points <= 84) return 5;
        return 6;

    }

    /**
     * Отива на следващия въпрос
     *
     * @param event
     */
    @FXML
    void goNextQuestion(ActionEvent event) {
        index++;
        setControlExamBtns();
        fillFields(questions.get(index));
    }

    /**
     * Връща се на предишния въпрос
     *
     * @param event
     */
    @FXML
    void goBackQuestion(ActionEvent event) {
        index--;
        setControlExamBtns();
        fillFields(questions.get(index));
    }

    /**
     * Задава бутоните за напред и назад
     * И ако сме на последния въпрос вече можем да пращаме
     */
    private void setControlExamBtns() {
        goNextBtn.setDisable(index + 1 == questions.size());
        goBackBtn.setDisable(index == 0);
        sendBtn.setDisable(!goNextBtn.isDisable());
    }

    /**
     * Задава полетата на текущия въпрос
     *
     * @param question
     */
    private void fillFields(Question question) {
        questionTxt.setText(question.getQuestion());
        fieldATxt.setText(question.getFieldA());
        fieldBTxt.setText(question.getFieldB());
        fieldCTxt.setText(question.getFieldC());
        fieldDTxt.setText(question.getFieldD());
        selectedAnswer.getToggles().forEach(t -> t.setSelected(false));
        QuestionOption studentAnswer = studentAnswerSheet.getStudentAnswers().get(index);
        if (studentAnswer != QuestionOption.NOT_ANSWERED)
            selectedAnswer.getToggles().get(studentAnswer.ordinal()).setSelected(true);
    }

    /**
     * Инициализира началния изгледни и данните от RMI сървъра
     */
    @FXML
    void initialize() {
        assert fieldATxt != null : "fx:id=\"fieldATxt\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert fieldBTxt != null : "fx:id=\"fieldBTxt\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert fieldCTxt != null : "fx:id=\"fieldCTxt\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert fieldDTxt != null : "fx:id=\"fieldDTxt\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert goBackBtn != null : "fx:id=\"goBackBtn\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert goNextBtn != null : "fx:id=\"goNextBtn\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert nameTxt != null : "fx:id=\"nameTxt\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert questionTxt != null : "fx:id=\"questionTxt\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert selectedAnswer != null : "fx:id=\"selectedAnswer\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert sendBtn != null : "fx:id=\"sendBtn\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert startExamBtn != null : "fx:id=\"startExamBtn\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert timeTxt != null : "fx:id=\"timeTxt\" was not injected: check your FXML file 'ClientExamScene.fxml'.";

        goNextBtn.setDisable(true);
        goBackBtn.setDisable(true);
        sendBtn.setDisable(true);
        selectedAnswer.getToggles().forEach(t -> {
            Node node = (Node) t;
            node.setDisable(true);
        });
        setupData();

        selectedAnswer.selectedToggleProperty().addListener((observableValue, oldToggle, newToggle) -> {
            if (newToggle instanceof RadioButton) {
                QuestionOption newAnswer = QuestionOption.valueOf(((RadioButton) newToggle).getText());
                studentAnswerSheet.setStudentAnswers(newAnswer, index);
            }
        });
    }


    /**
     * Взема въпросите, продължителността на изпита
     */
    private void setupData() {
        try {
            Registry r = LocateRegistry.getRegistry("localhost", 1099);
            try {
                exam = (Examinable) r.lookup("Exam");
            } catch (NotBoundException | AccessException ex) {
                ex.printStackTrace();
            }
            if (exam == null) {
                new Alert(Alert.AlertType.ERROR, "Exam is invalid due to problem with connecting the server").showAndWait();
                Platform.exit();
                System.exit(0);
                return;
            }
            questions = exam.getQuestions();
            duration = exam.getExamDuration();
        } catch (RemoteException ex) {
            ex.printStackTrace();
            new Alert(Alert.AlertType.ERROR, "Exam is invalid due to problem with connecting the server").showAndWait();
            Platform.exit();
            System.exit(0);
        }
    }


}
