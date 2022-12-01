package Zad1;

import com.sun.source.tree.Tree;
import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

import java.util.*;
import java.util.function.Consumer;
import java.util.function.Predicate;

class LambdaDemo {
    public static void main(String[] args) {
        Predicate<Salesperson> predicate1 = (salesperson -> salesperson.getNumSales() > 1200);
        Predicate<Salesperson> predicate2 = (salesperson -> salesperson.getSalary() > 900);
        Predicate<Salesperson> predicate = salesperson -> predicate1.test(salesperson) || predicate2.test(salesperson);

        Consumer<Salesperson> consumer1 = salesperson -> {
            salesperson.addBonus(salesperson.getSalary() * 0.05);
            System.out.println(salesperson);
        };
        Consumer<Salesperson> consumer2 = salesperson -> {
            if (predicate1.test(salesperson)) salesperson.addBonus(salesperson.getSalary() * 0.02);
            else salesperson.addBonus(-salesperson.getSalary() * 0.02);
            System.out.println(salesperson);
        };

        Comparator<Salesperson> comparator1 = new Comparator<Salesperson>() {
            @Override
            public int compare(Salesperson o1, Salesperson o2) {
                return Double.compare(o2.getSalary(), o1.getSalary());
            }
        };
        Comparator<Salesperson> comparator2 = new Comparator<Salesperson>() {
            @Override
            public int compare(Salesperson o1, Salesperson o2) {
                if (o1.getSalary() > o2.getSalary())
                    return -1;
                else if (o1.getSalary() < o2.getSalary())
                    return 1;
                else return Integer.compare(o2.getNumSales(), o1.getNumSales());
            }
        };

        Random rand = new Random();
        Salesperson[] salespersons =
                {
                        new Salesperson("John Doe", 2000, 949), //1
                        new Salesperson("Jane Doe", 3900, 1500), //2
                        new Salesperson("June Doe", rand.nextDouble(2000) + 2000, rand.nextInt(1000) + 500), //3
                        new Salesperson("Bine Doe", rand.nextDouble(2000) + 2000, rand.nextInt(1000) + 500), //4
                        new Salesperson("Boe Doe", rand.nextDouble(2000) + 2000, rand.nextInt(1000) + 500), //5
                        new Salesperson("Kue Doe", rand.nextDouble(2000) + 2000, rand.nextInt(1000) + 500), //6
                        new Salesperson("Lae Doe", rand.nextDouble(2000) + 2000, rand.nextInt(1000) + 500), //7
                        new Salesperson("Cie Doe", rand.nextDouble(2000) + 2000, rand.nextInt(1000) + 500), //8
                        new Salesperson("Lee Doe", rand.nextDouble(2000) + 2000, rand.nextInt(1000) + 500), //9
                        new Salesperson("Zeene Doe", rand.nextDouble(2000) + 2000, rand.nextInt(1000) + 500), //10
                        // да се добавят още 10 обекти от тип Salesperson
                        // или да се инициализират с Random стойности
                };
        List<Salesperson> listOfSalespersons = new ArrayList<>(Arrays.asList(salespersons));
        // обектите на salespersons да се запишат в listOfSalespersons

        for (Salesperson salesperson : salespersons) {
            System.out.println(salesperson);
            applyBonus(salesperson, predicate1, consumer1);
            salesperson.printNumSales(salesperson);

        }
        System.out.println("///////////////");
        for (Salesperson salesperson : salespersons) {
            System.out.println(salesperson);
            applyBonus(salesperson, predicate2, consumer2);
            System.out.println();
        }
        sort(listOfSalespersons, comparator1);
        System.out.println(listOfSalespersons);
        sort(listOfSalespersons, comparator2);
        System.out.println(listOfSalespersons);
        System.out.println("////////////////");
        group(List.of(salespersons));
    }

    public static void applyBonus(Salesperson salesperson,
                                  Predicate<Salesperson>
                                          predicate,
                                  Consumer<Salesperson> consumer) {
        if (predicate.test(salesperson))
            consumer.accept(salesperson);
        // Напишете if команда, където използвайте predicate
        // за да определите дали да изпълните consumer
        // Изпълнете consumer, когато условието на if командата е изпълнено
    }

    public static void applyBonus(List<Salesperson> salespersons,
                                  Predicate<Salesperson>
                                          predicate,
                                  Consumer<Salesperson> consumer) {
        for (Salesperson person : salespersons)
            if (predicate.test(person)) consumer.accept(person);
        // Напишете if команда, където използвайте predicate
        // за да определите дали да изпълните consumer
        // Изпълнете consumer, когато условието на if командата е изпълнено
    }

    public static void sort(List<Salesperson> salespersons,
                            Comparator<Salesperson>
                                    comparator) {
        salespersons.sort(comparator);
    }

    public static void group(List<Salesperson> salespersons) {
        TreeMap<Character, List<Salesperson>> nameGroups = new TreeMap<>();
        for (Salesperson person : salespersons) {
            char firstLetter = person.getName().charAt(0);
            if (!nameGroups.containsKey(firstLetter))
                nameGroups.put(firstLetter, new ArrayList<Salesperson>());

            nameGroups.get(firstLetter).add(person);
        }

        nameGroups.forEach((letter, group) -> {
            System.out.print(letter + ": ");
            for (Salesperson person : group)
                System.out.printf("%s, ", person.toString());
            System.out.println();
        });
        // Групирайте имената на salespersons по първата буква в
        // името изведете отделните групи на стандартен изход
    }
}

