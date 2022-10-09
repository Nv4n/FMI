package lab1.Zad4;

public class NucleotideChain {
    private int[] nucleotideChain;
    private final int size;

    public NucleotideChain(int size) {
        nucleotideChain = new int[size];
        this.size = size;
    }

    public void calculateNucleotideChain(int geneticInfo) {
        for (int i = size - 1; i >= 0; --i) {
            int stepsDivisions = (int) (geneticInfo / Math.pow(4, i));
            int nucBaseNumber = Math.min(stepsDivisions, 3);
            nucleotideChain[i] = nucBaseNumber;

            geneticInfo -= (nucBaseNumber * Math.pow(4, i));
        }
    }

    public void printBasesChain() {
        for (int i = 0; i < size; i++) {
            switch (nucleotideChain[i]) {
                case (0) -> System.out.print("A");
                case (1) -> System.out.print("C");
                case (2) -> System.out.print("G");
                case (3) -> System.out.print("T");
                default -> throw new IllegalStateException("Unexpected value: " + nucleotideChain[i]);
            }
        }
    }
}
