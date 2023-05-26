package Zad1AndZad2;

import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class ArrayListTest {
    private static ArrayList<String> list;

    public static void main(String[] args) {
//        DATA SET
//Gosho Petrov
//Lora Minkova
//Gosho Petrov
//Galya Martinova
//Gosho Petrov
//Lora Minkova
//Galya Martinova
//Samuela Evangelina Hra Minkova
//        list = new ArrayList<>();
//        System.out.println("Enter names till 'END':");
//        getNames();
//        System.out.println(list);
//        System.out.println("Sort by frequency");
//        sortByFrequency();
//        System.out.printf("Max el: %s%n", max(list));
//        System.out.printf("Removed: %s%n", removeMax(list));
//        System.out.println("Removed duplicates");
//        list = removeDuplicates(list);
//        System.out.println(list);
//        System.out.println("Test Append");
//        List<?> append = append(new ArrayList<>(), 10);
//        System.out.println(append);

        System.out.println("A)");
        list = new ArrayList<>(List.of(new String[]{"Лили", "Мария", "Георги", "Илия", "Цвета", "Георги"}));
        Iterator<String> nameIterator = list.iterator();
        System.out.println(nameIterator.next());
        nameIterator.next();
        System.out.println(nameIterator.next());
        nameIterator.remove();
        System.out.println(nameIterator.next());
        System.out.println(list);

        System.out.println("B)");
        nameIterator = new ArrayList<>(list).stream().sorted(Collections.reverseOrder()).iterator();
        while (nameIterator.hasNext()) System.out.println(nameIterator.next());

    }

    public static void sort() {
        list.sort(String::compareTo);
    }

    public static void sortByFrequency() {
        list.sort((elLvs, elRvs) -> {
            int res = Collections.frequency(list, elLvs) - Collections.frequency(list, elRvs);
            if (res == 0) {
                return elLvs.compareTo(elRvs);
            }
            return res;
        });
        System.out.println(list);
    }

    public static <E extends Comparable<E>> E max(E[][] list) {
        E max = null;
        for (E[] elRow : list)
            for (int col = 0; col < list[0].length; col++)
                if (max == null || max.compareTo(elRow[col]) < 0) max = elRow[col];
        return max;
    }

    public static <T extends Comparable<? super T>> T removeMax(List<T> someList) {
        T max = null;
        for (T el : someList)
            if (max == null || max.compareTo(el) < 0) max = el;
        if (!someList.isEmpty())
            someList.remove(max);
        return max;
    }

    public static void getNames() {
        Scanner input = new Scanner(System.in);
        String name = input.nextLine();
        while (!name.matches("END")) {
            list.add(name);
            name = input.nextLine();
        }

        removeDuplicates(list);
    }

    public static void copyTo(ArrayList<String> str) {
        if (!str.equals(list)) str = new ArrayList<>();
        str.addAll(list);
    }

    public static String toStringDescending() {
        ArrayList<String> desc = new ArrayList<>(list);
        desc.sort((elLvs, elRvs) -> {
            return -elLvs.compareTo(elRvs);
        });
        return String.join(":", desc);
    }

    public static List<?> append(List<? extends Number> numberSrc, Integer n) {
        List<Object> result = new ArrayList<>(numberSrc);
        result.add(n);
        return result;
    }

    public static <E> void shuffle(ArrayList<E> list) {
        Random rand = new Random();
        for (int i = list.size() - 1; i > 0; i--) {
            int ind = rand.nextInt(0, i);
            E temp = list.get(ind);
            E curr = list.get(i);
            list.set(ind, curr);
            list.set(i, temp);
        }
    }

    public static <E extends Comparable<E>> E max(ArrayList<E> list) {
        E max = null;
        for (E el : list)
            if (max == null || max.compareTo(el) < 0) max = el;
        return max;
    }

    public static <E> ArrayList<E> removeDuplicates(ArrayList<E> list) {
        return new ArrayList<>(new HashSet<>(list));
    }
}

