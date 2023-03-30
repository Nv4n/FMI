package com.problem1;

public class Stock {
    private final String symbol;
    private final String name;
    private double previousClosingPrice;
    private double currentPrice;

    public Stock(String symbol, String name) {
        this.symbol = symbol != null ? symbol : "Default symbol";
        this.name = name != null ? name : "Default name";
    }
    
    public String getSymbol() {
        return symbol;
    }

    public String getName() {
        return name;
    }

    public double getPreviousClosingPrice() {
        return previousClosingPrice;
    }

    public void setPreviousClosingPrice(double previousClosingPrice) {
        this.previousClosingPrice = previousClosingPrice;
    }

    public double getCurrentPrice() {
        return currentPrice;
    }

    public void setCurrentPrice(double currentPrice) {
        this.currentPrice = currentPrice;
    }

    public double changePercent() {
        return ((currentPrice / previousClosingPrice) * 100) - 100;
    }
}
