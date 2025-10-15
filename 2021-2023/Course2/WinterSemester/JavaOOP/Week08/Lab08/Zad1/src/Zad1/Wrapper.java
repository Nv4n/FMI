package Zad1;

import java.util.Random;

public class Wrapper {
    private int size;

    public Wrapper() {
        this(1);
    }

    public Wrapper(int size) {
        setSize(size);
    }

    public Wrapper(Wrapper other) {
        this(other.getSize());
    }

    private class FixedRandom implements Cipherable {

        @Override
        public char[] getSecretChars(int seed) {
            Random rand = new Random(seed);
            char[] secretArr = new char[size];

            for (int i = 0; i < secretArr.length; i++)
                secretArr[i] = (char) (rand.nextInt('Z' - 'A') + 'A');

            return secretArr;
        }
    }

    private class FixedSelection implements Cipherable {

        @Override
        public char[] getSecretChars(int seed) {
            Random rand = new Random();

            char[] subset = new char[3];
            for (int i = 0; i < subset.length; i++)
                subset[i] = (char) (rand.nextInt('Z' - 'A') + 'A');

            rand = new Random(seed);
            char[] secretArr = new char[size];

            for (int i = 0; i < secretArr.length; i++)
                secretArr[i] = subset[rand.nextInt(3)];

            return secretArr;
        }
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size > 0 ? size : 1;
    }

    public Cipherable makeFixedRandom() {
        return new FixedRandom();
    }

    public Cipherable makeFixedSelection() {
        return new FixedSelection();
    }
}
