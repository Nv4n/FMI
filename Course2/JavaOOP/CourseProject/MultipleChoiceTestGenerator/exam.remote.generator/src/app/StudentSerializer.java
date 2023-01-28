package app;

import obj.StudentAnswerSheet;

import java.beans.ExceptionListener;
import java.beans.XMLDecoder;
import java.beans.XMLEncoder;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

public class StudentSerializer {
    public static void serializeToXML(List<StudentAnswerSheet> students) throws IOException {
        FileOutputStream fos = new FileOutputStream("students.xml");
        XMLEncoder encoder = new XMLEncoder(fos);
        encoder.setExceptionListener(new ExceptionListener() {
            public void exceptionThrown(Exception e) {
                System.out.println("Exception! :" + e.toString());
            }
        });
        encoder.writeObject(students);
        encoder.close();
        fos.close();
    }

    public static List<StudentAnswerSheet> deserializeFromXML() throws IOException {
        FileInputStream fis = new FileInputStream("students.xml");
        XMLDecoder decoder = new XMLDecoder(fis);
        List<StudentAnswerSheet> decodedStudents = (List<StudentAnswerSheet>) decoder.readObject();
        decoder.close();
        fis.close();
        return decodedStudents;
    }
}
