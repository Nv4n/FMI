package lab4.hw;

public class RouteCipher {
    private int key;
    private static final char EMPTY_CHAR = 'Х';

    public RouteCipher(int key) {
        setKey(key);
    }

    public int getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key;
    }

    public String encrypt(String plaintText) {
        char[] textChars = plaintText.toCharArray();
        int cols = Math.abs(key);
        int rows = (int) Math.ceil(1.0 * plaintText.length() / cols);

        char[][] grid = new char[rows][cols];
        gridInits(textChars, grid);
        char[] result = new char[cols * rows];

        if (key < 0)
            initTopRight(rows - 1, 0, cols - 1, 0, grid, result, 0);
        else
            initBottomLeft(0, rows - 1, 0, cols - 1, grid, result, 0);

        return new String(result);
    }

    public String decrypt(String cipherText) {
        char[] textChars = cipherText.toCharArray();
        int cols = Math.abs(key);
        int rows = cipherText.length() / cols;

        if (rows * cols != textChars.length)
            throw new IllegalArgumentException("Invalid cipher length for current key: " + textChars.length);

        char[][] grid = new char[rows][cols];

        if (key < 0)
            fillTopRight(rows - 1, 0, cols - 1, 0, grid, textChars, 0);
        else
            fillBottomLeft(0, rows - 1, 0, cols - 1, grid, textChars, 0);

        char[] result = new char[cols * rows];
        for (int ri = 0, resInd = 0; ri < rows; ri++)
            for (int ci = 0; ci < cols; ci++)
                if (grid[ri][ci] != EMPTY_CHAR)
                    result[resInd++] = grid[ri][ci];

        return new String(result);
    }

    public String printNode() {
        return "key: " + key;
    }

    private void fillTopRight(int startRi, int endRi, int startCi, int endCi, char[][] grid, char[] textChars, int txtChrInd) {
        if (txtChrInd >= textChars.length)
            return;

        for (int i = startRi; i >= endRi; i--)
            grid[i][startCi] = textChars[txtChrInd++];

        for (int i = startCi - 1; i >= endCi; i--)
            grid[endRi][i] = textChars[txtChrInd++];

        fillBottomLeft(++endRi, startRi, endCi, --startCi, grid, textChars, txtChrInd);
    }

    private void fillBottomLeft(int startRi, int endRi, int startCi, int endCi, char[][] grid, char[] textChars, int txtChrInd) {
        if (txtChrInd >= textChars.length)
            return;

        for (int i = startRi; i <= endRi; i++)
            grid[i][startCi] = textChars[txtChrInd++];

        for (int i = startCi + 1; i <= endCi; i++)
            grid[endRi][i] = textChars[txtChrInd++];

        fillTopRight(--endRi, startRi, endCi, ++startCi, grid, textChars, txtChrInd);
    }

    private void initTopRight(int startRi, int endRi, int startCi, int endCi, char[][] grid, char[] result, int resInd) {
        if (resInd >= result.length)
            return;

        for (int i = startRi; i >= endRi; i--)
            result[resInd++] = grid[i][startCi];

        for (int i = startCi - 1; i >= endCi; i--)
            result[resInd++] = grid[endRi][i];

        initBottomLeft(++endRi, startRi, endCi, --startCi, grid, result, resInd);
    }

    private void initBottomLeft(int startRi, int endRi, int startCi, int endCi, char[][] grid, char[] result, int resInd) {
        if (resInd == result.length)
            return;

        for (int i = startRi; i <= endRi; i++)
            result[resInd++] = grid[i][startCi];

        for (int i = startCi + 1; i <= endCi; i++)
            result[resInd++] = grid[endRi][i];

        initTopRight(--endRi, startRi, endCi, ++startCi, grid, result, resInd);
    }

    private void gridInits(char[] textChars, char[][] grid) {
        for (int ri = 0, si = 0; ri < grid.length; ri++)
            for (int ci = 0; ci < grid[0].length; ci++)
                //Cyrillic X, so we can skip it in the decryption
                grid[ri][ci] = (si < textChars.length) ? textChars[si++] : EMPTY_CHAR;
    }
}
