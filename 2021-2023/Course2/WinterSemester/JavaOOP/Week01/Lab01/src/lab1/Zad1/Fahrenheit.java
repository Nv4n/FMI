package lab1.Zad1;

public class Fahrenheit {
    private double fahrenheit;

    public Fahrenheit(double fahrenheit) {
        setFahrenheit(fahrenheit);
    }

    public double getFahrenheit() {
        return fahrenheit;
    }

    public void setFahrenheit(double fahrenheit) {
        this.fahrenheit = fahrenheit;
    }

    public double convertToCelsius() {
        return 5.0 / 9.0 * (fahrenheit - 32); //Fahrenheit to Celsius conversion
    }
}
