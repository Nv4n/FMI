package com.model;

import org.jetbrains.annotations.NotNull;

public class Product {
    public enum ProdCategory {
        A, B, C, D
    }

    private static int prevId = 0;
    private final int INV_NUMBER;
    private String invDescription;
    private ProdCategory prodCategory;
    private double price;

    public Product() {
        this("Default description", ProdCategory.A, 1);
    }

    public Product(String invDescription, ProdCategory prodCategory, double price) {
        INV_NUMBER = ++prevId;
        setProdCategory(prodCategory);
        setInvDescription(invDescription);
        setPrice(price);
    }

    public Product(@NotNull Product other) {
        this(other.getInvDescription(), other.getProdCategory(), other.getPrice());
    }

    final public int getInvNumber() {
        return INV_NUMBER;
    }

    final public @NotNull String getInvDescription() {
        return invDescription;
    }

    final public void setInvDescription(@NotNull String invDescription) {
        this.invDescription = invDescription.isBlank() ? "Default description" : invDescription;
    }

    final public ProdCategory getProdCategory() {
        return prodCategory;
    }

    final public void setProdCategory(ProdCategory prodCategory) {
        this.prodCategory = prodCategory;
    }

    final public double getPrice() {
        return price;
    }

    final public void setPrice(double price) {
        this.price = price > 0 ? price : 1;
    }

    @Override
    public String nodeToString() {
        return String.format("""
                ID: %d
                Description: %s
                Price: %.2f
                """, INV_NUMBER, invDescription, price);
    }
}
