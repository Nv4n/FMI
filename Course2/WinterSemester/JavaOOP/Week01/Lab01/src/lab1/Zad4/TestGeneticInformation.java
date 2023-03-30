package lab1.Zad4;

import java.util.Scanner;

public class TestGeneticInformation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter genetic information: ");
        GeneticInformation geneticInformation = new GeneticInformation(scanner.nextInt());

        //Finding the max power of 4
        int maxDivider = 1;
        int maxPowerOf4 = 0;
        while (geneticInformation.getInfo() / maxDivider > 3) {
            maxDivider *= 4;
            maxPowerOf4++;
        }

        NucleotideChain nucleotideChain = new NucleotideChain(maxPowerOf4 + 1);

        nucleotideChain.calculateNucleotideChain(geneticInformation.getInfo());
        //Print the bases
        System.out.printf("Genetic information %d is translated to: ", geneticInformation.getInfo());
        nucleotideChain.printBasesChain();

        System.out.println();
    }
}
