package model;

public class AnimalInstance {
    private int animalKey;
    private String animalName;
    private int animalAge;
    private final String INSTANCE_ID;
    private static int idIndex = 0;

    public AnimalInstance(int animalKey, String animalName, int animalAge) {
        setAnimalKey(animalKey);
        setAnimalName(animalName);
        setAnimalAge(animalAge);
        INSTANCE_ID = String.format("%s %03d", animalName, idIndex);
        idIndex++;
    }

    final public String getINSTANCE_ID() {
        return INSTANCE_ID;
    }

    final public int getAnimalKey() {
        return animalKey;
    }

    final public void setAnimalKey(int animalKey) {
        this.animalKey = animalKey;
    }

    final public String getAnimalName() {
        return animalName;
    }

    final public void setAnimalName(String animalName) {
        this.animalName = animalName != null ? animalName : "Animal";
    }

    final public int getAnimalAge() {
        return animalAge;
    }

    final public void setAnimalAge(int animalAge) {
        this.animalAge = animalAge >= 0 ? animalAge : 1;
    }

    @Override
    public String toString() {
        return String.format("%s, Възраст: %d", INSTANCE_ID, animalAge);
    }
}
