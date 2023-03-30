package Zad1.b;

public class PhoneCoder {
    private int key;

    public PhoneCoder(int key) {
        setKey(key);
    }

    public PhoneCoder() {
        this(1);
    }

    public double getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key >= 1 && key <= 9 ? key : 1;
    }

    public String encode(String phoneNumber) {
        StringBuilder encodedNumber = new StringBuilder();
        for (int i = 0; i < phoneNumber.length(); i++) {
            int currentDigit = phoneNumber.codePointAt(i) - "0".codePointAt(0);
            int encodedDigit = (currentDigit + key) % 10;
            encodedNumber.append(encodedDigit);
        }
        return encodedNumber.toString();
    }

    public String decode(String codedPhoneNumber) {
        StringBuilder decodedNumber = new StringBuilder();
        for (int i = 0; i < codedPhoneNumber.length(); i++) {
            int currentDigit = codedPhoneNumber.codePointAt(i) - "0".codePointAt(0);
            int decodedDigit = currentDigit - key;
            decodedDigit = decodedDigit < 0 ? decodedDigit + 10 : decodedDigit;
            decodedNumber.append(decodedDigit);
        }
        return decodedNumber.toString();
    }

    @Override
    public String toString() {
        return "PhoneCoder : " + key;
    }
}
