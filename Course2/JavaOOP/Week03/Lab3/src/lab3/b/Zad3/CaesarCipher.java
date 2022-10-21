package lab3.b.Zad3;

public class CaesarCipher {
    private static final int SHIFT_LENGTH = 3;
    private static final int SHIFT = SHIFT_LENGTH % 26; // If the shift is larger than letter count

    public static String encrypt(String data) {
        char[] symbols = data.toCharArray();
        for (int i = 0; i < symbols.length; i++) {
            //26 = 'Z' - 'A' + 1
            //123 = 'z' + 1
            //91 = 'Z' + 1

            if (symbols[i] >= 'a' && symbols[i] <= 'z') {
                symbols[i] = (char) (symbols[i] + SHIFT);
                symbols[i] = symbols[i] > 'z' ? (char) (symbols[i] % 123 + 'a') : symbols[i];
            } else if (symbols[i] >= 'A' && symbols[i] <= 'Z') {
                symbols[i] = (char) (symbols[i] + SHIFT);
                symbols[i] = symbols[i] > 'Z' ? (char) (symbols[i] % 91 + 'A') : symbols[i];
            }
        }
        return new String(symbols);
    }

    public static String decrypt(String data) {
        char[] symbols = data.toCharArray();
        for (int i = 0; i < symbols.length; i++) {
            //26 = 'Z' - 'A' + 1
            
            if (symbols[i] >= 'a' && symbols[i] <= 'z') {
                symbols[i] = (char) (symbols[i] - SHIFT);
                symbols[i] = symbols[i] < 'a' ? (char) (symbols[i] + 26) : symbols[i];
            } else if (symbols[i] >= 'A' && symbols[i] <= 'Z') {
                symbols[i] = (char) (symbols[i] - SHIFT);
                symbols[i] = symbols[i] < 'A' ? (char) (symbols[i] + 26) : symbols[i];
            }
        }
        return new String(symbols);
    }
}
