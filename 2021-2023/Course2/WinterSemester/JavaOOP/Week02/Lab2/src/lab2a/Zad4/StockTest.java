package lab2a.Zad4;

import javax.swing.*;
import java.util.Optional;

public class StockTest {
    public static void main(String[] args) {
        String name = JOptionPane.showInputDialog("Input stock name:");
        String symbol = JOptionPane.showInputDialog("Input stock symbol:");
        Stock stock = new Stock(symbol, name);

        Optional<String> input = Optional.ofNullable(JOptionPane.showInputDialog("Input previous stock price:"));
        stock.setPreviousClosingPrice(Double.parseDouble(input.orElse("1")));

        input = Optional.ofNullable(JOptionPane.showInputDialog("Input current stock price:"));
        stock.setCurrentPrice(Double.parseDouble(input.orElse("1")));
        
        JOptionPane.showMessageDialog(null, String.format("""
                        Name: %s \s
                        Symbol: %s \s
                        Previous stock price: %.2f \s
                        Current stock price: %.2f \s
                        Percentage change: %.2f \s
                        """ ,
                stock.getName(), stock.getSymbol(),
                stock.getPreviousClosingPrice(), stock.getCurrentPrice(), stock.changePercent()));
    }
}
