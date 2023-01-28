package app;

import obj.Examinable;
import obj.questions.obj.Question;
import obj.StudentAnswerSheet;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class Exam extends UnicastRemoteObject implements Examinable {
    private List<Question> questions;
    private int questionsCount;
    private int examDuration;

    private List<StudentAnswerSheet> students;

    protected Exam() throws RemoteException {
        students = new ArrayList<>();
    }

    @Override
    public List<Question> getQuestions() throws RemoteException {
        if (questions == null) return null;

        List<Question> questionSubset = new ArrayList<>(questions);
        Collections.shuffle(questionSubset);
        return questionSubset.stream().limit(questionsCount).collect(Collectors.toList());
    }

    @Override
    public int getExamDuration() throws RemoteException {
        return examDuration;
    }

    @Override
    public void registerStudent(StudentAnswerSheet student) throws RemoteException {
        students.add(student);
    }


    public void setExamDuration(int examDuration) {
        this.examDuration = Math.max(examDuration, 1);
    }

    public void setQuestions(List<Question> questions) {
        this.questions = questions;
    }

    public int getQuestionsCount() {
        return questionsCount;
    }

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
