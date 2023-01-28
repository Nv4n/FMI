package app;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import obj.Examinable;
import obj.StudentAnswerSheet;
import obj.questions.obj.Question;

import java.net.URL;
import java.rmi.AccessException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.ResourceBundle;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

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
    private Button startExamBtn;

    @FXML
    private Label timeTxt;

    private Examinable exam;
    private List<Question> questions;
    private int index;
    private int duration;

    private StudentAnswerSheet studentAnswerSheet;

    @FXML
    void goBackQuestion(ActionEvent event) {
        index++;
        setNavQuestionsBtns();
    }

    @FXML
    void goNextQuestion(ActionEvent event) {
        index++;
        setNavQuestionsBtns();
    }

    @FXML
    void startExam(ActionEvent event) {
        if (nameTxt.getText().isEmpty()) {
            new Alert(Alert.AlertType.INFORMATION, "You need to get the questions first").showAndWait();

        }
    }

    private Runnable stop() {
        return () -> {
            try {
                if (studentAnswerSheet == null) return;
                exam.registerStudent(studentAnswerSheet);
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        };
    }

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
        assert startExamBtn != null : "fx:id=\"startExamBtn\" was not injected: check your FXML file 'ClientExamScene.fxml'.";
        assert timeTxt != null : "fx:id=\"timeTxt\" was not injected: check your FXML file 'ClientExamScene.fxml'.";

        goNextBtn.setDisable(true);
        goBackBtn.setDisable(true);
        index = 0;
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
            questions = new ArrayList<>(exam.getQuestions());
            duration = exam.getExamDuration();

            ScheduledExecutorService executorService = Executors.newSingleThreadScheduledExecutor();
            executorService.scheduleAtFixedRate(Objects.requireNonNull(stop()), 0, duration, TimeUnit.MINUTES);

        } catch (RemoteException ex) {
            ex.printStackTrace();
        }
    }

    private void setNavQuestionsBtns() {
        goNextBtn.setDisable(index + 1 == questions.size());
        goBackBtn.setDisable(index == 0);
    }
}
