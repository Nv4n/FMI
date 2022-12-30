package com.model;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.Random;

public class ListOfProducts<E extends Product> {
    private ArrayList<E> products;

    public ListOfProducts() {
        this.products = new ArrayList<>();
    }

    final public void setup() {
        Random random = new Random();
        Product.ProdCategory[] categories = Product.ProdCategory.values();
        for (int i = 0; i < 10; i++) {
            String description = random
                    .ints('a', 'z' + 1)
                    .limit(10)
                    .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
                    .toString();
            Product.ProdCategory category = categories[random.nextInt(categories.length)];
            double price = random.nextDouble();
            Product currentProduct = new Product(description, category, price);
            //TODO
            products.add((E) currentProduct);
        }
    }

    @Contract(value = " -> new", pure = true)
    final public @NotNull ArrayList<E> getProducts() {
        return new ArrayList<E>(products);
    }

    final public void setProducts(@NotNull ArrayList<E> products) {
        this.products = new ArrayList<E>(products);
    }

    final public double averagePrice() {
        return products.stream().mapToDouble(E::getPrice).average().orElse(0);
    }

    final public String @NotNull [] toArray() {
        return products.stream().map(E::toString).toArray(String[]::new);
    }

    @Override
    final public String toString() {
        return "[" + products.stream().map(E::toString).reduce("", (acc, el) -> acc + "," + el) + "]";
    }
}
