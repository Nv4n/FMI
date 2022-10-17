package lab3.a.Zad6;

public class SizeOfTest {
    public static void main(String[] args) {
        sizeof(null);
        printByteSizes();
    }

    private static void printByteSizes() {
        System.out.printf("""
                        size of byte in Java is (in bytes) : %d
                        size of short in Java is (in bytes) : %d
                        size of char in Java is (in bytes) : %d
                        size of int in Java is (in bytes) : %d
                        size of long in Java is (in bytes) : %d
                        size of float in Java is (in bytes) : %d
                        size of double in Java is (in bytes) : %d
                        """,
                sizeof(byte.class),
                sizeof(short.class),
                sizeof(char.class),
                sizeof(int.class),
                sizeof(long.class),
                sizeof(float.class),
                sizeof(double.class));
    }

    public static int sizeof(Class dataType) {
        return switch (dataType.getTypeName()) {
            case "byte" -> 1;
            case "short", "char" -> 2;
            case "int", "float" -> 4;
            case "long", "double" -> 8;
            default -> 0;
        };
    }
}
