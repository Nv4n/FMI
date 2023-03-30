package com.calculator;

public class Calculator {
    private double data;

    Calculator() {
        data = 0;
    }

    public double getData() {
        return data;
    }

    public void setData(double data) {
        this.data = data;
    }

    public void plus(double otherNum) {
        data += otherNum;
    }

    public void minus(double otherNum) {
        data -= otherNum;
    }

    public void multiply(double otherNum) {
        data *= otherNum;
    }

    public void divide(double otherNum) throws IllegalArgumentException {
        if (otherNum == 0) {
            throw new IllegalArgumentException("Cannot divide by 0");
        }
        data /= otherNum;
    }

}
