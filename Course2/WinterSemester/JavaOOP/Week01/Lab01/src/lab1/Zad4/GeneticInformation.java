package lab1.Zad4;

public class GeneticInformation {
    private int info;

    public GeneticInformation(int geneticInformation) {
        setInfo(geneticInformation);
    }

    public int getInfo() {
        return info;
    }

    public void setInfo(int info) {
        //Data validation
        if (info < 1000 || info > 9999)
            throw new IllegalArgumentException("Illegal geneticInformation (must be 4 digits): ");

        this.info = info;
    }
}
