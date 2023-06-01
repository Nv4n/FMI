package model;

import java.util.Arrays;

public class Result {
    private char[] chars;
    private int data;

    public Result(char[] chars, int data) {
        setChars(chars);
        setData(data);
    }

    public char[] getChars() {
        char[] _chars = new char[chars.length];
        for (int i = 0; i < chars.length; i++) _chars[i] = chars[i];
        return chars;
    }

    public void setChars(char[] _chars) {
        chars = new char[_chars.length];
        for (int i = 0; i < chars.length; i++) chars[i] = _chars[i];
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = Math.max(data, 0);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Result{");
        sb.append("chars=").append(Arrays.toString(chars));
        sb.append(", data=").append(data);
        sb.append('}');
        return sb.toString();
    }
}
