package lab4.a.Zad4;

public class TransCipher {
    private final int CIPHER_KEY;

    public TransCipher(String cipherKey) {
        CIPHER_KEY = cipherKey.length();
    }

    public String encrypt(String data) {
        char[] chars = data.toCharArray();
        char[][] grid = new char[Math.ceilDiv(chars.length, CIPHER_KEY)][CIPHER_KEY];
        char[] result = new char[grid.length * grid[0].length];

        for (int ri = 0, i = 0; ri < grid.length; ri++)
            for (int ci = 0; ci < grid[0].length; ci++)
                if (i < chars.length)
                    grid[ri][ci] = chars[i++];
                else
                    grid[ri][ci] = ' ';


        int excessArea = CIPHER_KEY - (chars.length % CIPHER_KEY);
        for (int ci = 0, i = 0; ci < grid[0].length; ci++)
            for (int ri = 0; ri < grid.length; ri++)
                if (grid[ri][ci] != ' ')
                    result[i++] = grid[ri][ci];
                else
                    result[result.length - (excessArea--)] = ' ';

        return new String(result);
    }

    public String decrypt(String data) {
        char[] chars = data.toCharArray();
        if (chars.length % CIPHER_KEY != 0)
            throw new IllegalArgumentException("Data length is invalid for decrypting: " + chars.length);

        char[] result = new char[chars.length];
        char[][] grid = new char[chars.length / CIPHER_KEY][CIPHER_KEY];

        int spacesCount = 0;
        {
            int i = chars.length - 1;
            while (chars[i] == ' ') {
                i--;
                spacesCount++;
            }
        }
        // FIXME: 10/28/2022
        //  decrypt cant decrypt with spaces
        int spaceStartCi = grid[0].length - 1 - spacesCount;
        for (int ci = 0, i = 0; ci < grid[0].length; ci++)
            for (int ri = 0; ri < grid.length; ri++)
                if (ri != grid.length - 1 || ci < spaceStartCi)
                    grid[ri][ci] = chars[i++];
                else
                    grid[ri][grid[0].length - 1 - spacesCount--] = ' ';


        for (int ri = 0, i = 0; ri < grid.length; ri++)
            for (int ci = 0; ci < grid[0].length; ci++)
                if (grid[ri][ci] != ' ')
                    result[i++] = grid[ri][ci];

        return new String(result);
    }
}
