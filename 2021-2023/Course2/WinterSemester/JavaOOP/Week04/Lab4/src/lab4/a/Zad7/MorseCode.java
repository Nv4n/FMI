package lab4.a.Zad7;

public class MorseCode {
    private final String[] code = new String[]{
            //region Letters codes
            /* A */ ".-",
            /* B */ "-...",
            /* C */ "-.-.",
            /* D */ "-..",
            /* E */ ".",
            /* F */ "..-.",
            /* G */ "--.",
            /* H */ "....",
            /* I */ "..",
            /* J */ ".---",
            /* K */ "-.-",
            /* L */ ".-..",
            /* M */ "--",
            /* N */ "-.",
            /* O */"---",
            /* P */ ".--.",
            /* Q */ "--.--",
            /* R */ ".-.",
            /* S */"...",
            /* T */ "-",
            /* U */ "...-",
            /* V */ "...-",
            /* W */ ".--",
            /* X */ "-..-",
            /* Y */"-.--",
            /* Z */ "--.."
            //endregion
    };

    public String encode(String text) {
        char[] letters = text.toCharArray();
        int[] codeIndexes = new int[letters.length];

        for (int li = 0; li < letters.length; li++)
            codeIndexes[li] = letters[li] - 'A';

        int resultLength = 0;
        for (int ci : codeIndexes)
            resultLength += code[ci].length();

        char[] result = new char[resultLength + letters.length - 1];
        for (int cii = 0, ri = 0; cii < codeIndexes.length; cii++) {

            char[] curr = code[codeIndexes[cii]].toCharArray();
            for (int ci = 0; ci < curr.length; ci++, ri++) {
                result[ri] = curr[ci];
            }
            if (ri + 1 < result.length)
                result[ri++] = ' ';
        }

        return new String(result);
    }

    public String decode(String morse) {
        char[] symbols = morse.toCharArray();
        int resultLength = 1; //Count last word

        for (char s : symbols)
            if (s == ' ')
                resultLength++;

        char[] result = new char[resultLength];

        for (int si = 0, symbolCount = 0, ri = 0;
             si <= symbols.length;
             si++, symbolCount++) {
            if (si == symbols.length || symbols[si] == ' ') {
                char[] currCodeArr = new char[symbolCount--];

                for (int i = si - 1; i >= 0 && symbols[i] != ' '; i--, symbolCount--)
                    currCodeArr[symbolCount] = symbols[i];

                String currCode = new String(currCodeArr);
                for (int i = 0; i < code.length; i++) {
                    if (currCode.equals(code[i])) {
                        result[ri++] = (char) (i + 'A');
                        break;
                    }
                }
            }
        }

        return new String(result);
    }
}
