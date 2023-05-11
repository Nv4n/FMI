package model;

public class Calculator {
    private double memory;
    private boolean hasSaved;
    private double currentValue;
    private Operation operation;

    public Calculator() {
        setHasSaved(false);
        operation = Operation.UNKNOWN;
    }

    public double getMemory() {
        return memory;
    }

    public void setMemory(double memory) {
        this.memory = memory;
    }

    public boolean isHasSaved() {
        return hasSaved;
    }

    public void setHasSaved(boolean hasSaved) {
        this.hasSaved = hasSaved;
    }

    public double getCurrentValue() {
        return currentValue;
    }

    public void setCurrentValue(double currentValue) {
        this.currentValue = currentValue;
    }

    public Operation getOperation() {
        return operation;
    }

    public void setOperation(Operation operation) {
        this.operation = operation;
    }

    public void compute() {
        switch (operation) {
            case PLUS -> memory += currentValue;
            case MINUS -> memory -= currentValue;
            case MULTIPLY -> memory *= currentValue;
            case DIVIDE -> {
                if (currentValue == 0) {
                    operation = Operation.UNKNOWN;
                    throw new IllegalArgumentException("You can't divide by 0");
                }
                memory /= currentValue;
            }
        }
        operation = Operation.UNKNOWN;
    }

    public void clearMemory() {
        hasSaved = false;
    }
}
