package model;

public enum AnimalType {
    BIRD("Птица"),
    MAMMAL("Бозайник"),
    REPTILE("Влечуго"),
    FISH("Риба");

    private final String typeName;

    final public String getTypeName() {
        return typeName;
    }

    private AnimalType(String typeName) {
        this.typeName = typeName;
    }
}
