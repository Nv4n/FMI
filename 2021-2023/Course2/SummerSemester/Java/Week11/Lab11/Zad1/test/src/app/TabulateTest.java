package app;

import models.Functions;
import models.Tabulate;

public class TabulateTest {
    public static void main(String[] args) {
        Functions funcs = new Functions();
        Tabulate sinTabulate = new Tabulate(funcs.getSinFunction());
        Tabulate expTabulate = new Tabulate(funcs.getExpFunction());

        System.out.println("\tsin tabulate");
        sinTabulate.tabulate(1, 10, 5);
        System.out.println("\t1/x tabulate");
        Tabulate.tabulateFunction(-5.43, 50, 30, (a) -> 1 / a);
    }
}
