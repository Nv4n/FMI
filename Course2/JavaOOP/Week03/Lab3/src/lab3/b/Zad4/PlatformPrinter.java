package lab3.b.Zad4;

import javax.swing.*;
import java.util.Arrays;

public class PlatformPrinter {
    private int[] sequence;

    public PlatformPrinter(int[] sequence) {
        setSequence(sequence);
    }

    private void setSequence(int[] sequence) {
        this.sequence = Arrays.copyOf(sequence, sequence.length);
        Arrays.sort(this.sequence);
    }

    public void printAllPlatforms() {
        System.out.println(Arrays.nodeToString(sequence));
        if (sequence.length == 0) {
            alert();
            return;
        }

        System.out.printf("Start\tLength\tElement%n");
        int currStartIndex = 0;
        int currLength = 1;
        int currElement = sequence[0];

        boolean hasPlatforms = false;
        for (int i = 1; i < sequence.length; i++) {
            if (sequence[i] != currElement) {
                hasPlatforms = isPlatform(currStartIndex, currLength, currElement);
                currLength = 0;
                currStartIndex = i;
                currElement = sequence[i];
            }

            currLength++;
        }
        hasPlatforms = hasPlatforms || isPlatform(currStartIndex, currLength, currElement);

        if (!hasPlatforms) {
            alert();
            return;
        }
    }

    private boolean isPlatform(int startIndex, int length, int el) {
        if (length > 1) {
            printPlatform(startIndex, length, el);
            return true;
        }
        return false;
    }

    private void printPlatform(int startIndex, int length, int element) {
        System.out.printf("%5d\t%6d\t%7d%n", startIndex, length, element);
    }

    private void alert() {
        JOptionPane.showMessageDialog(null,
                "No platforms have been found!",
                "Alert",
                JOptionPane.WARNING_MESSAGE);
    }
}
