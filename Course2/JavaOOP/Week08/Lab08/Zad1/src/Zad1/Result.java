package Zad1;

import java.util.Arrays;

public class Result {
    private char[] chars;
    private int data;

    public Result(char[] chars, int data) {
        setChars(chars);
        setData(data);
    }

    public char[] getChars() {
        char[] tmp = new char[chars.length];
        System.arraycopy(chars, 0, tmp, 0, tmp.length);
        return tmp;
    }

    public void setChars(char[] chars) {
        this.chars = new char[chars.length];
        System.arraycopy(chars, 0, this.chars, 0, this.chars.length);
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = Math.max(data, 0);
    }

    @Override
    public String toString() {
        return "Chars: " + Arrays.toString(chars) +
                "\nResult: " + data;
    }
}
