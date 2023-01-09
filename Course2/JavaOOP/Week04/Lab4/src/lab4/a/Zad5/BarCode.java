package lab4.a.Zad5;

public class BarCode {
    private static final byte[][] code = {
            //7 4  2  1  0
            {0, 0, 0, 1, 1}, //1
            {0, 0, 1, 0, 1}, //2
            {0, 0, 1, 1, 0}, //3
            {0, 1, 0, 0, 1}, //4
            {0, 1, 0, 1, 0}, //5
            {0, 1, 1, 0, 0}, //6
            {1, 0, 0, 0, 1}, //7
            {1, 0, 0, 1, 0}, //8
            {1, 0, 1, 0, 0}, //9
            {1, 1, 0, 0, 0}, //0
    };

    public static String decode(int zip) {
        if (zip < 100 || zip > 999)
            throw new IllegalArgumentException("Zip number must be with length of 3: " + zip);
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 100; i > 0; i /= 10) {
            int digit = zip / i;
            zip %= i;
            int index = digit != 0 ? digit - 1 : 9;

            for (int j = 0; j < 5; j++)
                stringBuilder.append(code[index][j] == 0 ? ':' : '|');
        }

        return stringBuilder.printNode();
    }
}
