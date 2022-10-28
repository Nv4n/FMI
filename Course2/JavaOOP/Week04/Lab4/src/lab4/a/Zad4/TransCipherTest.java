package lab4.a.Zad4;

public class TransCipherTest {
    public static void main(String[] args) {
        TransCipher transCipher = new TransCipher("beauty");
        printSetOfCiphers(transCipher, "thisistheplaintext");
        printSetOfCiphers(transCipher, "thisaintatext");
    }

    private static void printSetOfCiphers(TransCipher transCipher, String input) {
        String encryptedResult = transCipher.encrypt(input);
        System.out.println(encryptedResult);

        String decryptedResult = transCipher.decrypt(encryptedResult);
        System.out.println(decryptedResult);
    }
}
