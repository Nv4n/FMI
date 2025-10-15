package model;

import java.util.Random;

public class Coin {
    private Random rand;
    private Face face;

    public Coin(Face face) {
        setFace(face);
        rand = new Random();
    }

    public Face getFace() {
        return face;
    }

    public void setFace(Face face) {
        this.face = face;
    }

    public void flip() {
        face = face == Face.HEAD ? Face.TAIL : Face.HEAD;
    }

    public boolean isHeads() {
        return face == Face.HEAD;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Coin{");
        sb.append("face=").append(face);
        sb.append('}');
        return sb.toString();
    }
}
