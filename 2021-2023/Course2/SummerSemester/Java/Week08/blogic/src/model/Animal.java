package model;

public class Animal {
    private String name;
    private AnimalType animalType;
    private boolean predator;
    private String region;
    private boolean endangered;
    public static final String[] REGIONS = new String[]{"Africa", "Asia", "Australia", "Europe", "America" };

    public Animal(String name, AnimalType animalType, boolean predator, String region, boolean endangered) {
        setName(name);
        setAnimalType(animalType);
        setPredator(predator);
        setRegion(region);
        setEndangered(endangered);
    }

    final public String getName() {
        return name;
    }

    final public void setName(String name) {
        this.name = name != null ? name : "Animal";
    }

    final public AnimalType getAnimalType() {
        return animalType;
    }

    final public void setAnimalType(AnimalType animalType) {
        this.animalType = animalType;
    }

    final public boolean isPredator() {
        return predator;
    }

    final public void setPredator(boolean predator) {
        this.predator = predator;
    }

    final public String getRegion() {
        return region;
    }

    final public void setRegion(String region) {
        for (String reg : REGIONS)
            if (reg.equals(region)) {
                this.region = region;
                return;
            }

        this.region = "UNKNOWN";
    }

    final public boolean isEndangered() {
        return endangered;
    }

    final public void setEndangered(boolean endangered) {
        this.endangered = endangered;
    }

    @Override
    public String toString() {
        return String.format("Животно{ %s, тип= %s, хищник= %s, район= %s, застрашен= %s}",
                name,
                animalType.getTypeName(),
                predator ? "Да" : "Не",
                region,
                endangered ? "Да" : "Не");
    }
}
