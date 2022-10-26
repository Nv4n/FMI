package lab4.a.Zad4;

public class TransCipher {
    private final int CIPHER_KEY;

    public TransCipher(String cipherKey) {
        CIPHER_KEY = cipherKey.length();
    }

    public String encrypt(String data) {
        char[] chars = data.toCharArray();
        int excessLength = chars.length % CIPHER_KEY != 0 ? CIPHER_KEY - chars.length % CIPHER_KEY : 0;
        char[] result =
                new char[chars.length + excessLength];
        //If the length is not dividable by CIPHER_KEY

        for (int i = 0, ri = 0; i < CIPHER_KEY; i++)
            for (int j = i; j < result.length; j += CIPHER_KEY, ri++)
                if (j >= chars.length) {
                    result[j] = ' ';
                    ri--;
                } else result[ri] = chars[j];

        return new String(result);
    }

    public String decrypt(String data) {
        char[] chars = data.toCharArray();
        if (chars.length % CIPHER_KEY != 0) {
            throw new IllegalArgumentException("Data length is invalid for decrypting: " + chars.length);
        }

        char[] result = new char[chars.length];
        int sectionsCount = chars.length / CIPHER_KEY;
        for (int i = 0, ri = 0; i < sectionsCount; i++)
            for (int j = i; j < result.length; j += sectionsCount, ri++)
                if (chars[j] != ' ') {
                    result[ri] = chars[j];
                }
        // FIXME: 10/25/2022
        //  Encrypt and decrypt with matrix

        return new String(result);
    }
}
