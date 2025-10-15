package model;

public class MonetaryCoin extends Coin {
    private int value;

    public MonetaryCoin(Face face, int value) {
        super(face);
        setValue(value);
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = Math.max(value, 1);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("MonetaryCoin{");
        sb.append("face=").append(getFace());
        sb.append(", value=").append(value);
        sb.append('}');
        return sb.toString();
    }
}
