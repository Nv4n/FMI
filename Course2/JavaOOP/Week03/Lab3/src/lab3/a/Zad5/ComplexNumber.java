package lab3.a.Zad5;

public class ComplexNumber {
    private double imaginaryPart;
    private double realPart;

    public ComplexNumber(double imaginaryPart, double realPart) {
        this.imaginaryPart = imaginaryPart;
        this.realPart = realPart;
    }

    public double getImaginaryPart() {
        return imaginaryPart;
    }

    public double getRealPart() {
        return realPart;
    }

    public double getAngle() {
        return Math.atan2(imaginaryPart, realPart);
    }

    public double getMagnitude() {
        return Math.sqrt((realPart * realPart) + (imaginaryPart * imaginaryPart));
    }

    public ComplexNumber add(ComplexNumber other) {
        return new ComplexNumber(other.imaginaryPart, other.realPart);
    }
}
