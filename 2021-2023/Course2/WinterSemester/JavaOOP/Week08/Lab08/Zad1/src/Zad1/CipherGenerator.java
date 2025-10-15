package Zad1;

public class CipherGenerator {
    public Result countDistinct(Cipherable cipher, int seed) {
        char[] symbols = cipher.getSecretChars(seed);

        int[] flags = new int[26];
        for (char symbol : symbols)
            flags[symbol - 'A']++;

        int count = 0;
        for (int flag : flags)
            if (flag == 1)
                count++;
        return new Result(symbols, count);
    }
}
