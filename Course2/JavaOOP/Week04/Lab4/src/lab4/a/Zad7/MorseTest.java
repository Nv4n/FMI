package lab4.a.Zad7;

public class MorseTest {
    public static void main(String[] args) {
        MorseCode morseCode = new MorseCode();

        String encoded = morseCode.encode("EXAM");
        String decoded = morseCode.decode(encoded);

        System.out.printf("Morse code:\t%1$s%nPlain text:\t%2$s",
                encoded,
                decoded);
    }
}
