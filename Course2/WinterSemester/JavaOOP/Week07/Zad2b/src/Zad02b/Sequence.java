package Zad02b;

import org.jetbrains.annotations.NotNull;

public class Sequence {
    private Object[] obs;
    private int next;

    public Sequence(int size) {
        next = 0;
        obs = new Object[size > 0 ? size : 1];
    }

    public void add(@NotNull Object x) {
        if (next < obs.length)
            obs[next++] = x;
    }

    private class SSelectorForward implements SelectorForward {

        private int i = 0;

        @Override
        public Object current() {
            return obs[i];
        }

        @Override
        public boolean end() {
            return i >= obs.length;
        }

        @Override
        public void next() {
            if (i < obs.length) i++;
        }
    }

    private class SSelectorBackward implements SelectorBackwards {
        private int i = obs.length - 1;

        @Override
        public Object current() {
            return obs[i];
        }

        @Override
        public boolean begin() {
            return i < 0;
        }

        @Override
        public void previous() {
            if (i >= 0) i--;
        }
    }

    private class SSelectorTwoWay implements SelectorTwoWay {

        private int i;

        public SSelectorTwoWay(int index) {
            i = index >= 0 && index < obs.length ? index : 0;
        }

        @Override
        public Object current() {
            return obs[i];
        }

        @Override
        public boolean begin() {
            return i < 0;
        }

        @Override
        public void previous() {
            if (i >= 0) i--;
        }

        @Override
        public boolean end() {
            return i >= obs.length;
        }

        @Override
        public void next() {
            if (i < obs.length) i++;
        }
    }

    public SSelectorForward getSelectorForward() {
        return new SSelectorForward();
    }

    public SSelectorBackward getSelectorBackward() {
        return new SSelectorBackward();
    }

    public SSelectorTwoWay getSelectorTwoWay() {
        return new SSelectorTwoWay(obs.length / 2);
    }
}
