package model;

public class Staff extends Employee {
    private String workAt;

    public Staff() {
        super();
        setWorkAt("Candidate");
    }

    public Staff(String name, double salary, String workAt) {
        super(name, salary);
        setWorkAt(workAt);
    }

    public Staff(Staff other) {
        super(other);
        setWorkAt(other.workAt);
    }

    public String getWorkAt() {
        return workAt;
    }

    public void setWorkAt(String workAt) {
        this.workAt = workAt != null ? workAt : "Candidate";
    }

    @Override
    public String toString() {
        return String.format("%s, work at: %s", super.toString(), workAt);
    }
}
