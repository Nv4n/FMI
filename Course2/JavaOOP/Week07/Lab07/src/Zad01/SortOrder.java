package Zad01;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

public class SortOrder {
    private static class Upward implements Sortable {

        @Override
        public boolean greaterThan(int a, int b) {
            return a > b;
        }
    }

    private static class Downward implements Sortable {

        @Override
        public boolean greaterThan(int a, int b) {
            return a < b;
        }
    }

    @Contract(value = " -> new", pure = true)
    public static @NotNull Sortable getUpward() {
        return new Upward();
    }

    @Contract(value = " -> new", pure = true)
    public static @NotNull Sortable getDownward() {
        return new Downward();
    }
}
