package models;


import implementable.Computable;

public class Functions {
    private static class SinFunction implements Computable {

        @Override
        public double function(double x) {
            return Math.sin(x);
        }
    }

    private static class ExpFunction implements Computable {

        @Override
        public double function(double x) {
            return Math.exp(x);
        }
    }

    public Computable getSinFunction() {
        return new SinFunction();
    }

    public Computable getExpFunction() {
        return new ExpFunction();
    }

}
