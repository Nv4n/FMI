package Zad2;

import java.util.Arrays;

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
        return new String(type);
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
        String[] res = new String[files.length];
        for (int i = 0; i < files.length; i++)
            res[i] = new String(files[i]);
        return res;
    }

    public void setFiles(String[] files) {
        if (files == null) {
            this.files = new String[]{""};
            return;
        }

        this.files = new String[files.length];
        for (int i = 0; i < files.length; i++)
            this.files[i] = new String(files[i]);
    }

    @Override
    public String toString() {
        return String.format("""
                Computer {
                Type: %s
                Proc Speed: %5d
                Files: %s
                }
                """, type, procSpeed, Arrays.toString(files));
    }
}
