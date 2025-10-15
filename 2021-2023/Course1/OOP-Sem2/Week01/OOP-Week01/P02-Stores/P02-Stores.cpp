// P02-Stores.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Product {
	char name[25];
	char brand[25];
	bool foodType; // 0 for veggitable and 1 for fruit
	unsigned int quantity;
	double price;
};

struct Store {
	char name[25];
	int productsCount;
	Product* products;
	unsigned int maxCapacity;
};

#pragma region FunctionsInitilization
void printStore(const Store& store);
void printProduct(const Product& product);

void sortStoreByFruitFirst(Store& store);
void sortStoreByVegetablesFirst(Store& store);
void sortStoreByPrice(Store& store);

void addProductToTheStore(Store& store, const Product& product);
void sellProductFromTheStore(Store& store, unsigned int productIndex, unsigned int quantity);

Store getStoreWithMostFruit(const Store* stores, const size_t storesCount);
Store getStoreWithMostVeggies(const Store* stores, const size_t storesCount);
Store getCheapestStore(const Store* stores, const size_t storesCount);
Store getMostExpensiveStore(const Store* stores, size_t storesCount);

void initiliazeProduct(Product& product);
void initiliazeStore(Store& store);
void deleteStore(Store& store);
void deleteProduct(Product& product);
#pragma endregion

int main()
{
	const int storesCount = 3;
	Store stores[storesCount];  // the default constructor of "Store" cannot be referenced

	for (int i = 0; i < storesCount; i++) {
		initiliazeStore(stores[i]);
		std::cout << std::endl;
	}

	sortStoreByFruitFirst(stores[0]);
	sortStoreByVegetablesFirst(stores[1]);
	sortStoreByPrice(stores[2]);

	printStore(getStoreWithMostFruit(stores, storesCount));
	printStore(getStoreWithMostVeggies(stores, storesCount));
	printStore(getCheapestStore(stores, storesCount));
	printStore(getMostExpensiveStore(stores, storesCount));

	for (int i = 0; i < storesCount; i++) {
		deleteStore(stores[i]);
	}
}

void initiliazeProduct(Product& product) {
	std::cout << "Name: ";
	std::cin.ignore();
	std::cin.getline(product.name, 24);

	std::cout << "Brand: ";
	std::cin.ignore();
	std::cin.getline(product.brand, 24);
	do
	{
		std::cout << "0) Veggitable\n1) Fruit" << std::endl;
		std::cin >> product.foodType;
	} while (product.foodType >= 0 && product.foodType <= 1);

	std::cout << "Quantity: ";
	std::cin >> product.quantity;

	std::cout << "Price: ";
	std::cin >> product.price;
}

void initiliazeStore(Store& store) {
	std::cout << "Store name: ";
	std::cin.ignore();
	std::cin.getline(store.name, 24);

	std::cout << "Products max capacity: ";
	std::cin >> store.maxCapacity;
	do
	{
		std::cout << "Products count: " << store.productsCount;
	} while (store.productsCount <= store.maxCapacity);

	store.products = new Product[store.maxCapacity];
	for (int storeIndex = 0; storeIndex < store.productsCount; storeIndex++) {
		initiliazeProduct(store.products[storeIndex]);
	}
}

void deleteStore(Store& store) {
	delete[] store.name;
	for (int productIndex = 0; productIndex < store.productsCount; productIndex++) {
		deleteProduct(store.products[productIndex]);
	}
	delete[] store.products;
}

void deleteProduct(Product& product) {
	delete[] product.brand;
	delete[] product.name;
}

#pragma region PrintFunctions
void printStore(const Store& store) {
	std::cout << "Name: " << store.name << std::endl
		<< "Max products capacity: " << store.maxCapacity << std::endl
		<< "Products count: " << store.productsCount << std::endl;
	for (int i = 0; i < store.productsCount; i++) {
		printProduct(store.products[i]);
	}
}
void printProduct(const Product& product) {
	std::cout << "Name:" << product.name << std::endl
		<< "Brand: " << product.brand << std::endl
		<< "Product type: " << (product.foodType ? "fruit" : "vegetable") << std::endl
		<< "Quantity: " << product.quantity << std::endl
		<< "Price: " << product.price << "\n\n";
}
#pragma endregion

#pragma region SortFunctions
void sortStoreByFruitFirst(Store& store) {
	for (int lastElement = 0; lastElement < store.productsCount; lastElement++)
	{
		for (int productIndex = store.productsCount - 1; productIndex > 0; productIndex--) {
			if (store.products[productIndex].foodType == 0) {
				continue;
			}
			else if (store.products[productIndex - 1].foodType == 0) {
				Product temp = store.products[productIndex];
				store.products[productIndex] = store.products[productIndex - 1];
				store.products[productIndex - 1] = temp;
			}
		}
	}

}
void sortStoreByVegetablesFirst(Store& store) {
	for (int lastElement = 0; lastElement < store.productsCount; lastElement++)
	{
		for (int productIndex = store.productsCount - 1; productIndex > 0; productIndex--) {
			if (store.products[productIndex].foodType == 1) {
				continue;
			}
			else if (store.products[productIndex - 1].foodType == 1) {
				Product temp = store.products[productIndex];
				store.products[productIndex] = store.products[productIndex - 1];
				store.products[productIndex - 1] = temp;
			}
		}
	}
}

void sortStoreByPrice(Store& store) {
	for (int lastElement = 0; lastElement < store.productsCount; lastElement++)
	{
		for (int productIndex = store.productsCount - 1; productIndex > 0; productIndex--) {
			if (store.products[productIndex - 1].price > store.products[productIndex].price) {
				Product temp = store.products[productIndex];
				store.products[productIndex] = store.products[productIndex - 1];
				store.products[productIndex - 1] = temp;
			}
		}
	}
}
#pragma endregion

#pragma region AddSellProducts

void addProductToTheStore(Store& store, const Product& product) {
	if (store.productsCount + 1 <= store.maxCapacity) {
		store.products[store.productsCount] = product;
	}
	else {
		std::cout << "There is no space in the store!" << std::endl;
	}
}
void sellProductFromTheStore(Store& store, unsigned int productIndex, unsigned int quantity) {
	if (store.products[productIndex].quantity - quantity >= 0) {
		store.products[productIndex].quantity -= quantity;
	}
}
#pragma endregion

#pragma region StoreFunctions
Store getStoreWithMostXTypeProduct(const Store* stores, const size_t storesCount, bool foodType) {
	int maxProductCount = -1;
	int storeWithMostProductTypeIndex = 0;

	for (int storeIndex = 0; storeIndex < storesCount; storeIndex++) {
		int currentCount = 0;

		for (int productIndex = 0; productIndex < stores[storeIndex].productsCount; productIndex++) {
			if (stores[storeIndex].products[productIndex].foodType == foodType) {
				currentCount++;
			}
		}

		if (maxProductCount < currentCount) {
			storeWithMostProductTypeIndex = storeIndex;
		}
	}

	return stores[storeWithMostProductTypeIndex];
}

Store getStoreWithMostFruit(const Store* stores, const size_t storesCount) {
	return getStoreWithMostXTypeProduct(stores, storesCount, 1);
}

Store getStoreWithMostVeggies(const Store* stores, const size_t storesCount) {
	return getStoreWithMostXTypeProduct(stores, storesCount, 0);
}

Store getCheapestStore(const Store* stores, const size_t storesCount) {
	double maxValue = -1;
	int mostExpensiveStoreIndex = 0;

	for (int storeIndex = 0; storeIndex < storesCount; storeIndex++) {
		double currentValue = 0;

		for (int productIndex = 0; productIndex < stores[storeIndex].productsCount; productIndex++) {
			currentValue += stores[storeIndex].products[productIndex].price;
		}

		if (mostExpensiveStoreIndex < currentValue) {
			mostExpensiveStoreIndex = storeIndex;
		}
	}

	return stores[mostExpensiveStoreIndex];
}
Store getMostExpensiveStore(const Store* stores, size_t storesCount) {
	double minValue = INT_MAX;
	int cheapestStoreIndex = 0;

	for (int storeIndex = 0; storeIndex < storesCount; storeIndex++) {
		double currentValue = 0;

		for (int productIndex = 0; productIndex < stores[storeIndex].productsCount; productIndex++) {
			currentValue += stores[storeIndex].products[productIndex].price;
		}

		if (minValue > currentValue) {
			cheapestStoreIndex = storeIndex;
		}
	}

	return stores[cheapestStoreIndex];
}
#pragma endregion