package com.controller;

import com.model.ListOfProducts;
import com.model.Product;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.util.converter.DoubleStringConverter;
import org.jetbrains.annotations.NotNull;

import java.net.URL;
import java.util.*;

import static java.util.stream.Collectors.*;

public class ProductManagerController implements Initializable {
    @FXML
    private TextArea txtInfo;
    @FXML
    private TextField txtDescription;
    @FXML
    private TextField txtPrice;
    @FXML
    private ComboBox<String> cboCategory;
    private ListOfProducts<Product> listOfProducts;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        listOfProducts = new ListOfProducts<>();
        resetFields();
        txtPrice.setTextFormatter(new TextFormatter<>(new DoubleStringConverter()));
    }

    public void addToList(ActionEvent actionEvent) {
        String description = txtDescription.getText().trim();
        String priceText = txtPrice.getText().trim();
        if (priceText.isBlank()) {
            new Alert(Alert.AlertType.ERROR, "Price must have value").showAndWait();
            return;
        }
        double price = Double.parseDouble(priceText.isBlank() ? "0" : priceText);
        Product.ProdCategory category = Product.ProdCategory.valueOf(cboCategory.getValue());
        Product newProduct = new Product(description, category, price);
        @NotNull ArrayList<Product> temp = listOfProducts.getProducts();
        temp.add(newProduct);
        listOfProducts.setProducts(temp);
        new Alert(Alert.AlertType.INFORMATION, "New Product added!").showAndWait();

        resetFields();
    }

    public void sortProducts(ActionEvent actionEvent) {
        @NotNull ArrayList<Product> temp = listOfProducts.getProducts();
        temp.sort(Comparator.comparingDouble(Product::getPrice));
        listOfProducts.setProducts(temp);
    }

    public void showProducts(ActionEvent actionEvent) {
        String priceText = txtPrice.getText().trim();
        if (priceText.isBlank()) {
            new Alert(Alert.AlertType.ERROR, "Price must have value").showAndWait();
            return;
        }
        double price = Double.parseDouble(priceText.isBlank() ? "0" : priceText);

        txtInfo.setText(
                listOfProducts.getProducts().stream()
                        .filter(product -> product.getPrice() >= price)
                        .map(Product::toString)
                        .reduce("", (acc, el) -> acc + '\n' + el)
                        .trim());
    }

    public void averagePrice(ActionEvent actionEvent) {
        txtInfo.setText("Average price: " +
                String.valueOf(Math.round(listOfProducts.getProducts().stream()
                        .mapToDouble(Product::getPrice)
                        .average()
                        .orElse(0) * 100) / 100.0));
    }

    public void groupByCategory(ActionEvent actionEvent) {
        Map<Product.ProdCategory, List<Product>> categorizedProducts =
                listOfProducts.getProducts().stream()
                        .collect(groupingBy(Product::getProdCategory,
                                TreeMap::new,
                                toList()));

        StringBuilder result = new StringBuilder();
        categorizedProducts.forEach((category, products) -> {
            result.append("Category: ").append(category.toString()).append("\n");
            result.append(products.stream()
                    .map(Product::toString)
                    .reduce("", (acc, el) -> acc + '\n' + el)
                    .trim());
            result.append("\n");
        });

        txtInfo.setText(result.nodeToString());
    }

    private void resetFields() {
        txtDescription.setText("");
        cboCategory.setValue("A");
        txtPrice.setText("0.0");
    }


}
