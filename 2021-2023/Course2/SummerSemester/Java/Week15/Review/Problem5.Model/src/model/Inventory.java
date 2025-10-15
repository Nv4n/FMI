package model;
import javafx.beans.binding.Bindings;
import javafx.beans.binding.BooleanExpression;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;

public class Inventory {
    private String id;

    private String name;
    private int qoh;
    private int rop;
    private double sellPrice;

    public Inventory(String id, String name, double sellPrice) {
        setId(id);
        setName(name);
        setSellPrice(sellPrice);
    }

    public Inventory(String id, String name, int qoh, int rop, double sellPrice) {
        this(id, name, sellPrice);
        setQoh(qoh);
        setRop(rop);
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        if (!id.matches("^[A-Z]{3}-[0-9]{6}$")) {
            this.id = this.id.isBlank() ? "ABC-001234" : this.id;
            return;
        }
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getQoh() {
        return qoh;
    }

    public void setQoh(int qoh) {

        IntegerProperty qohProperty = new SimpleIntegerProperty(this.qoh);
        IntegerProperty ropProperty = new SimpleIntegerProperty(this.rop);
qohProperty.bindBidirectional();
        BooleanExpression isQohLessThanOrEqualToRop = Bindings.lessThanOrEqual(qohProperty, ropProperty);
Bindings.bindBidirectional(qoh,rop);
        // Modifying the values of the properties
        qohProperty.set(5);
        ropProperty.set(3);
        this.qoh = ;
    }

    public int getRop() {
        return rop;
    }

    public void setRop(int rop) {
        this.rop = rop;
    }

    public double getSellPrice() {
        return sellPrice;
    }

    public void setSellPrice(double sellPrice) {
        this.sellPrice = sellPrice;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Inventory{");
        sb.append("id='").append(id).append('\'');
        sb.append(", name='").append(name).append('\'');
        sb.append(", goh=").append(qoh);
        sb.append(", rop=").append(rop);
        sb.append(", sellPrice=").append(sellPrice);
        sb.append('}');
        return sb.toString();
    }
}
