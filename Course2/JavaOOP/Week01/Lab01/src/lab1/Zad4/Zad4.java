package lab1.Zad4;

import java.util.Scanner;

public class Zad4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter genetic information: ");
        int geneticInformation = scanner.nextInt();

        //Data validation
        if (geneticInformation < 1000 || geneticInformation > 9999)
            throw new IllegalArgumentException("Illegal geneticInformation (must be 4 digits): ");

        int maxDivider = 1;
        int maxIndex = 0;
        while (geneticInformation / maxDivider > 3) {
            maxDivider *= 4;
            maxIndex++;
        }
        maxIndex++;

        int originalGeneticInformation = geneticInformation;
        int[] nucleotideChain = new int[maxIndex];
        int sum = 0;
        for (int i = maxIndex - 1; i >= 0; --i) {
            int stepsDivisions = (int) (geneticInformation / Math.pow(4, i));
            int nucBaseNumber = Math.min(stepsDivisions, 3);
            nucleotideChain[i] = nucBaseNumber;

            sum += nucBaseNumber * Math.pow(4, i);
            geneticInformation -= (nucBaseNumber * Math.pow(4, i));
        }

        System.out.printf("Genetic information %d is translated to: ", originalGeneticInformation);

        for (int i = 0; i < maxIndex; i++) {
            switch (nucleotideChain[i]) {
                case (0) -> System.out.print("A");
                case (1) -> System.out.print("C");
                case (2) -> System.out.print("G");
                case (3) -> System.out.print("T");
                default -> throw new IllegalStateException("Unexpected value: " + nucleotideChain[i]);
            }
        }
        System.out.println();
        System.out.printf("Sum is: %d%n", sum);
    }
}
