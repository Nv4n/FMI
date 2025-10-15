package model;

import implementable.Cipherable;

import java.util.Random;

public class Wrapper {
    private int size;

    public Wrapper(int size) {
        setSize(size);
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size > 0 ? size : 1;
    }

    public Cipherable makeFixedSelection() {
        return new FixedSelection();
    }

    public Cipherable makeFixedRandom() {
        return new FixedRandom();
    }

    private class FixedRandom implements Cipherable {
        final private char[] letters;

        public FixedRandom() {
            letters = new char['Z' - 'A' + 1];
            char letter = 'A';
            for (int i = 0; i < letters.length; i++) {
                letters[i] = letter;
                letter++;
            }
        }

        @Override
        public char[] getSecretChars(int seed) {
            char[] secret = new char[size];
            int[] indexes = getSecretNumbers(seed);
            for (int i = 0; i < secret.length; i++)
                secret[i] = letters[indexes[i]];
            return secret;
        }

        private int[] getSecretNumbers(int seed) {
            Random rand = new Random(seed);
            int[] indexes = new int[size];
            for (int i = 0; i < indexes.length; i++)
                indexes[i] = rand.nextInt(0, indexes.length);
            return indexes;
        }
    }

    private class FixedSelection implements Cipherable {
        private final char[] letters;

        public FixedSelection() {
            letters = new char['Z' - 'A' + 1];
            char letter = 'A';
            for (int i = 0; i < letters.length; i++) {
                letters[i] = letter;
                letter++;
            }
        }

        @Override
        public char[] getSecretChars(int seed) {
            Random rand = new Random(seed);
            char[] secret = new char[size];
            for (int i = 0; i < secret.length; i++)
                secret[i] = letters[rand.nextInt(0, letters.length)];
            return secret;
        }
    }
}
