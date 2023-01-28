import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class Test {
    public static void main(String[] args) throws IOException {
        ExamQuestionsBank questionsBank = new ExamQuestionsBank();
        questionsBank.initializeQuestions();
        Consumer<ExamQuestionsBank> serializeToXML = questions -> {
            try {
                QuestionSerializer.serializeToXML(questions.getQuestionsList());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        };

        serializeToXML.accept(questionsBank);

        List<Question> array = QuestionSerializer.deserializeFromXML();
        System.out.println(array);
    }
}
