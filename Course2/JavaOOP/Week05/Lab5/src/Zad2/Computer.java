package Zad2;

public class Computer {
    private String type;
    private int procSpeed;
    private String[] files;

    public Computer() {
        this("DefaultName", 1000, null);
    }

    public Computer(String type, int procSpeed, String[] files) {
        setType(type);
        setProcSpeed(procSpeed);
        setFiles(files);
    }

    public Computer(Computer other) {
        this(other.getType(), other.getProcSpeed(), other.getFiles());
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type != null ? new String(type) : "DefaultName";
    }

    public int getProcSpeed() {
        return procSpeed;
    }

    public void setProcSpeed(int procSpeed) {
        this.procSpeed = procSpeed > 0 ? procSpeed : 1000;
    }

    public String[] getFiles() {
        return files;
    }

    public void setFiles(String[] files) {
        this.files = files;
    }
}
