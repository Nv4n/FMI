import java.beans.ExceptionListener;
import java.beans.XMLDecoder;
import java.beans.XMLEncoder;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

public class QuestionSerializer {
    public static void serializeToXML(List<Question> questions) throws IOException {
        FileOutputStream fos = new FileOutputStream("questions.xml");
        XMLEncoder encoder = new XMLEncoder(fos);
        encoder.setExceptionListener(new ExceptionListener() {
            public void exceptionThrown(Exception e) {
                System.out.println("Exception! :" + e.toString());
            }
        });
        encoder.writeObject(questions);
        encoder.close();
        fos.close();
    }

    public static List<Question> deserializeFromXML() throws IOException {
        FileInputStream fis = new FileInputStream("questions.xml");
        XMLDecoder decoder = new XMLDecoder(fis);
        List<Question> decodedQuestions = (List<Question>) decoder.readObject();
        decoder.close();
        fis.close();
        return decodedQuestions;
    }
}
