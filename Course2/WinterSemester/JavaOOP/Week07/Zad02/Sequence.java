package Zad02;

public class Sequence {
    // Holds a sequence of Objects.
    private Object[] obs;
    private int next = 0;

    public Sequence(int size) {
        obs = new Object[size];
    }

    public void add(Object x) {
        if (next < obs.length) {
            obs[next] = x;
            next++;
        }
    }

    private class Sselector implements Selector {
        // inner class манипулира преместване от първия към последния
        int i = 0;

        public boolean end() {
            return i == obs.length;
        }

        public Object current() {
            return obs[i];
        }

        public void next() {
            if (i < obs.length) i++;
        }
    } // end of inner class

    private class Rselector implements Selector {
        private int i = obs.length - 1;

        public boolean end() {
            return i < 0;
        }

        public Object current() {
            return obs[i];
        }

        public void next() {
            if (i >= 0) i--;
        }

    }

    public Selector getSelector() {
        return new Sselector();
    }

    public Selector getRSelector() {
        return new Rselector();
    }
}
