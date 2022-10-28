package lab4.hw;

public class RouteCipherTest {
    public static void main(String[] args) {
        RouteCipher routeCipher = new RouteCipher(5);
        String encryptInput = "ABORTTHEMISSIONYOUHAVEBEENSPOTTED";
        String positive = routeCipher.encrypt(encryptInput);

        routeCipher.setKey(-routeCipher.getKey());
        String negative = routeCipher.encrypt(encryptInput);
        String decryptNegative = routeCipher.decrypt(negative);

        routeCipher.setKey(4);
        String encryptInput2 = "THISISPLAINTEXT";
        String decryptInput = routeCipher.encrypt(encryptInput2);
        String decrypt = routeCipher.decrypt(decryptInput);

        System.out.printf("""
                        Input:\t%1$s
                        Positive %2$d:\t%3$s
                        Negative %4$d:\t%5$s
                        Decrypt:\t%6$s
                        Decrypt Input:\t%7$s
                        Decrypt:\t%8$s
                        """,
                encryptInput,
                5,
                positive,
                -5,
                negative,
                decryptNegative,
                decryptInput,
                decrypt);

        System.out.println(routeCipher.toString());
    }
}
