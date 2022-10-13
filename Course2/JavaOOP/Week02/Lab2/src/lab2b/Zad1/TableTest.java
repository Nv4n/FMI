package lab2b.Zad1;

import javax.swing.*;
import java.util.Optional;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;

public class TableTest {
    public static void main(String[] args) {
        Optional<String> start = Optional.ofNullable(JOptionPane.showInputDialog("Input start of interval:"));
        Optional<String> end = Optional.ofNullable(JOptionPane.showInputDialog("Input end of interval:"));
        Optional<String> steps = Optional.ofNullable(JOptionPane.showInputDialog("Input steps:"));

//        double startValue = parseDouble(start.orElse("1"));
//        double endValue = parseDouble(end.orElse("2"));
//        if(startValue>endValue){
//            double temp = startValue;
//            startValue=endValue;
//            endValue=temp
//        }

        //It's better practice Table to check which value is greater
        Table table = new Table(
                parseDouble(start.orElse("1")),
                parseDouble(end.orElse("2")),
                parseInt(steps.orElse("1")));

        table.makeTable();
    }
}
