package problem2;

import java.util.Arrays;
import java.util.List;

public class StreamTest {
    public static void main(String[] args) {
        String[] texts = new String[]{"aBc", "d", "ef", "123456"};
        List<String> list = Arrays.stream(texts)
                .map(String::toUpperCase)
                .sorted(String::compareTo)
                .toList();
        System.out.println(list);
    }
}
