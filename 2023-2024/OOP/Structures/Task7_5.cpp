//
// Created by Sybatron on 2/25/2024.
//
#include <iostream>
#include <fstream>

struct Product {
    int partNum;
//номер на изделие
    double cost;
//цена на изделие
    char description[32];
//описание на изделие
};

void printProductData(Product p) {
    std::cout << "Product { description: " << p.description
              << ", partNum: " << p.partNum
              << ", cost: " << p.cost << "}"
              << std::endl;
}

int main() {
//    Product prod1 = Product{"screw driver", 456, 5.50};
//    Product prod2 = Product{"hammer", 324, 8.20};
//    printProductData(prod1);
//    printProductData(prod2);
//    Product *productArr = new Product[5];
//    for (int i = 0; i < 5; ++i) {
//        productArr[i] = {};
//    }
//    productArr[0] = {"screw driver", 456, 5.50};
//    productArr[1] = {"hammer", 324, 8.2};
//    productArr[2] = {"socket", 777, 6.8};
//    productArr[3] = {"plier", 123, 10.8};
//    productArr[4] = {"hand-saw", 555, 12.8};
//    std::cout << "Product[] {" << std::endl;
//    for (int i = 0; i < 5; ++i) {
//        std::cout << "[" << i << "] ";
//        printProductData(productArr[i]);
//    }
//    std::cout << "}" << std::endl;

//    description partNum cost
//    screw driver 456 5.50
//    hammer 324 8.20
//    socket 777 6.80
//    plier 123 10.80
//    hand-saw 555 12.80
//
//    delete[] productArr;

    int prodSize;
    std::cin >> prodSize;
    Product *productArr = new Product[prodSize];
    std::ifstream read("products.txt", std::ios::binary);
    if (read.is_open()) {
        int index = 0;
        while (!read.eof() || index < prodSize) {
            Product product;
            read.read(reinterpret_cast<char *>(&product), sizeof(Product));
            productArr[index] = product;
            index++;
        }
    } else {
        for (int i = 0; i < prodSize; ++i) {
            std::cout << "Cost: ";
            std::cin >> productArr[i].cost;
            std::cout << "ParnNum: ";
            std::cin >> productArr[i].partNum;
            std::cin.ignore();
            std::cout << "Name: ";
            std::cin.getline(productArr[i].description, 31, '\n');

        }
    }
    read.close();
    for (int i = 0; i < prodSize; ++i) {
        printProductData(productArr[i]);
    }
    std::ofstream write("products.txt", std::ios::binary);
    if (write.is_open()) {
        for (int i = 0; i < prodSize; ++i) {
            write.write(reinterpret_cast<const char *>(&productArr[i]), sizeof(Product));
            char *something;
            int size = 3;
            write.write(reinterpret_cast<const char *>(&size), sizeof(int));
            write.write(reinterpret_cast<const char *>(&something), sizeof(size));
        }
    }

    write.close();

    delete[] productArr;
}