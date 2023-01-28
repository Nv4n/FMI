package remote.app;

import remote.obj.StudentAnswerSheet;

import java.beans.XMLDecoder;
import java.beans.XMLEncoder;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

/**
 * Сериализатор и десериализатор на изпитен лист с отговори
 */
public class StudentSerializer {
    /**
     * Сериализира единичен ученик до XML
     *
     * @param student
     * @throws IOException
     */
    public static void serializeToXML(StudentAnswerSheet student) throws IOException {
        FileOutputStream fos = new FileOutputStream(String.format("%s.xml", student.getStudentName()));
        XMLEncoder encoder = new XMLEncoder(fos);
        encoder.setExceptionListener(e -> System.out.println("Exception! :" + e.toString()));
        encoder.writeObject(student);
        encoder.close();
        fos.close();
    }

    /**
     * @param name
     * @return Връща десериализирания ученик
     * @throws IOException
     */
    public static StudentAnswerSheet deserializeFromXML(String name) throws IOException {
        FileInputStream fis = new FileInputStream(String.format("%s.xml", name));
        XMLDecoder decoder = new XMLDecoder(fis);
        StudentAnswerSheet decodedStudent = (StudentAnswerSheet) decoder.readObject();
        decoder.close();
        fis.close();
        return decodedStudent;
    }
}
