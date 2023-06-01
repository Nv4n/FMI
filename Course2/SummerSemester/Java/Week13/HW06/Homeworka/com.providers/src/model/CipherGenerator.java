package model;

import implementable.Cipherable;

public class CipherGenerator {

    public static Result countDistinct(Cipherable cipher, int seed) {
        if (cipher == null) return new Result(new char[0], seed);

        char[] secret = cipher.getSecretChars(seed);
        int[] lettersCount = new int['Z' - 'A' + 1];

        for (char c : secret) lettersCount[c - 'A']++;
        int distinct = 0;
        for (int count : lettersCount)
            if (count == 1) distinct++;
        return new Result(secret, distinct);
    }
}
