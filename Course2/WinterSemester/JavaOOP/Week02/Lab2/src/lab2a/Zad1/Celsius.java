package lab2a.Zad1;

public class Celsius {
    private double celsius;

    public Celsius(double celsius) {
        setCelsius(celsius);
    }

    public double getCelsius() {
        return celsius;
    }

    public void setCelsius(double celsius) {
        this.celsius = celsius;
    }

    public double convertToFahrenheit(){
        return 9.0 / 5.0 * celsius + 32;
    }
}
