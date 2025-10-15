package remote.app;

import obj.questions.obj.Question;
import remote.obj.Examinable;
import remote.obj.StudentAnswerSheet;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Клас, който действа remote между клиента и сървърното приложение
 */
public class Exam extends UnicastRemoteObject implements Examinable {
    private List<Question> questions;
    private int questionsCount;
    private int examDuration;

    private List<StudentAnswerSheet> students;

    protected Exam() throws RemoteException {
        students = new ArrayList<>();
    }

    /**
     * @return Връща точно определен брой в
     * разбъркан ред въпроси от банката с въпроси
     * @throws RemoteException
     */
    @Override
    public List<Question> getQuestions() throws RemoteException {
        if (questions == null) return null;

        List<Question> questionSubset = new ArrayList<>(questions);
        Collections.shuffle(questionSubset);
        return questionSubset.stream().limit(questionsCount).collect(Collectors.toList());
    }

    /**
     * @return Връща продължителността на изпита
     * @throws RemoteException
     */
    @Override
    public int getExamDuration() throws RemoteException {
        return examDuration;
    }

    /**
     * Метод, който регистрира ученика в списъка с ученици, които са предали
     *
     * @param student
     * @throws RemoteException
     */
    @Override
    public void registerStudent(StudentAnswerSheet student) throws RemoteException {
        students.add(student);
    }

    /**
     * @return Връща всички ученици, които са предали работата си
     */
    public List<StudentAnswerSheet> getStudents() {
        return new ArrayList<>(students);
    }

    /**
     * Метод, който задава стойност на продължителността на изпита
     *
     * @param examDuration
     */
    public void setExamDuration(int examDuration) {
        this.examDuration = Math.max(examDuration, 1);
    }

    /**
     * Метод, който задава всичките въпроси, които може да ги има на изпита
     *
     * @param questions
     */
    public void setQuestions(List<Question> questions) {
        this.questions = questions;
    }

    /**
     * @return Връща бройката на въпросите на всеки индивидуален изпитен лист
     */
    public int getQuestionsCount() {
        return questionsCount;
    }

    /**
     * Задава колко въпроса ще има на всеки изпитен лист
     *
     * @param questionsCount
     */
    public void setQuestionsCount(int questionsCount) {
        if (questionsCount > questions.size())
            throw new RuntimeException("Exam's question count should be less than " + (questions.size() + 1));
        this.questionsCount = Math.max(questionsCount, 1);
    }
    
    @Override
    public String toString() {
        return "Exam{" + "questionsCount=" + questionsCount +
                ", examDuration=" + examDuration +
                '}';
    }
}
