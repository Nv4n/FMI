//
// Created by Sybatron on 2/25/2024.
//
#include <iostream>

struct Product {
    char description[32];
//описание на изделие
    int partNum;
//номер на изделие
    double cost;
//цена на изделие
};

void printProductData(Product p) {
    std::cout << "Product { description: " << p.description
              << ", partNum: " << p.partNum
              << ", cost: " << p.cost << "}"
              << std::endl;
}

int main() {
    Product prod1 = Product{"screw driver", 456, 5.50};
    Product prod2 = Product{"hammer", 324, 8.20};
    printProductData(prod1);
    printProductData(prod2);
    Product *productArr = new Product[5];
    for (int i = 0; i < 5; ++i) {
        productArr[i] = {};
    }
    productArr[0] = {"screw driver", 456, 5.50};
    productArr[1] = {"hammer", 324, 8.2};
    productArr[2] = {"socket", 777, 6.8};
    productArr[3] = {"plier", 123, 10.8};
    productArr[4] = {"hand-saw", 555, 12.8};
    std::cout << "Product[] {" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "[" << i << "] ";
        printProductData(productArr[i]);
    }
    std::cout << "}" << std::endl;

//    description partNum cost
//    screw driver 456 5.50
//    hammer 324 8.20
//    socket 777 6.80
//    plier 123 10.80
//    hand-saw 555 12.80

    delete[] productArr;
}