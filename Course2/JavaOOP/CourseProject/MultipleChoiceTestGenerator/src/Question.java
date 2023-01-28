import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

public class Question {
    private String question;
    private String fieldA;
    private String fieldB;
    private String fieldC;
    private String fieldD;
    private QuestionOption rightAnswer;

    public Question() {
        this("default",
                "default",
                "default",
                "default",
                "default",
                QuestionOption.A);
    }

    public Question(
            @NotNull String question,
            @NotNull String fieldA,
            @NotNull String fieldB,
            @NotNull String fieldC,
            @NotNull String fieldD,
            QuestionOption rightAnswer) {
        setQuestion(question);
        setFieldA(fieldA);
        setFieldB(fieldB);
        setFieldC(fieldC);
        setFieldD(fieldD);
        setRightAnswer(rightAnswer);
    }

    @Contract(value = " -> new", pure = true)
    final public @NotNull String getQuestion() {
        return new String(question);
    }

    final public void setQuestion(String question) {
        this.question = question;
    }

    @Contract(value = " -> new", pure = true)
    final public @NotNull String getFieldA() {
        return new String(fieldA);
    }

    final public void setFieldA(String fieldA) {
        this.fieldA = fieldA;
    }

    @Contract(value = " -> new", pure = true)
    final public @NotNull String getFieldB() {
        return new String(fieldB);
    }

    final public void setFieldB(String fieldB) {
        this.fieldB = fieldB;
    }

    @Contract(value = " -> new", pure = true)
    final public @NotNull String getFieldC() {
        return new String(fieldC);
    }

    final public void setFieldC(String fieldC) {
        this.fieldC = fieldC;
    }

    @Contract(value = " -> new", pure = true)
    final public @NotNull String getFieldD() {
        return new String(fieldD);
    }

    final public void setFieldD(String fieldD) {
        this.fieldD = fieldD;
    }

    final public QuestionOption getRightAnswer() {
        return rightAnswer;
    }

    final public void setRightAnswer(QuestionOption rightAnswer) {
        this.rightAnswer = rightAnswer;
    }
}
