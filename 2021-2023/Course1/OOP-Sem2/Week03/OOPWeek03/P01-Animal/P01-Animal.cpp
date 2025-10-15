// P01-Animal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include  <fstream>
#include <string>

enum TYPE_ANIMAL
{
	UNKNOWN = -1,
	DOG,
	CAT,
	RABBIT,
	ANIMAL_COUNT
};

struct Animal {
	TYPE_ANIMAL animalType;
	char name[25];
	char gender;
	unsigned int age;
};

struct ZooMag {
	char storeName[21];
	Animal listOfAnimals[50];
	const int maxAnimalCapacity = 50;
	int numberOfAnimals = 0;
};

void addAnimal(ZooMag& store, const Animal& animal);
void printAnimalInfo(const ZooMag& store, char* name, TYPE_ANIMAL animal);

void saveInfoAboutAnimal(const char* filePath, const Animal& animal);
void readInfoAboutAnimal(const char* filePath, const Animal& animal);

void initializeAnimal(Animal& animal);

int main()
{

	return 0;
}

void addAnimal(ZooMag& store, const Animal& animal) {
	if (store.numberOfAnimals + 1 <= store.maxAnimalCapacity) {
		for (int i = 0; animal.name[i] != '\0'; i++) {
			store.listOfAnimals[store.numberOfAnimals].name[i] = animal.name[i];
		}
		store.listOfAnimals[store.numberOfAnimals].animalType = animal.animalType;
		store.listOfAnimals[store.numberOfAnimals].age = animal.age;
		store.numberOfAnimals += 1;
	}
	else {
		std::cout << "The store is full.";
	}
}

void printAnimalInfo(const ZooMag& store, char* name, TYPE_ANIMAL animalType) {
	int animalIndex = -1;
	for (int i = 0; i < store.numberOfAnimals; i++) {
		if (std::strcmp(store.listOfAnimals[i].name, name) == 0 && store.listOfAnimals[i].animalType == animalType) {
			animalIndex = i;
			break;
		}
	}

	if (animalIndex == -1) {
		std::cout << "Animal not found!" << std::endl;
	}
	else {
		switch (store.listOfAnimals[animalIndex].animalType) {
		case TYPE_ANIMAL::DOG:
			std::cout << "dog" << std::endl;
			break;
		case TYPE_ANIMAL::CAT:
			std::cout << "cat" << std::endl;
			break;
		case TYPE_ANIMAL::RABBIT:
			std::cout << "rabbit" << std::endl;
			break;
		default:
			std::cout << "unkown" << std::endl;
			break;
		}

		std::cout << "Name: " << store.listOfAnimals[animalIndex].name << std::endl
			<< "Gender: " << store.listOfAnimals[animalIndex].gender << std::endl
			<< "Age: " << store.listOfAnimals[animalIndex].age << std::endl;
	}
}

void initializeAnimal(Animal& animal) {
	int animalType;
	std::cin >> animalType;
	if (animalType > TYPE_ANIMAL::UNKNOWN && animalType < TYPE_ANIMAL::ANIMAL_COUNT) {
		animal.animalType = (TYPE_ANIMAL)animalType;
	}
	else {
		animal.animalType = TYPE_ANIMAL::UNKNOWN;
	}

	std::cin.getline(animal.name, 24);
	std::cin >> animal.gender;
	std::cin >> animal.age;
}

void saveAnimalInfoToFile(char* filePath, const Animal& animal) {
	std::ofstream fileWriteStream(filePath);

	if (!fileWriteStream.is_open()) {
		std::cout << "Unseccsful file opening!" << std::endl;
		return;
	}

	switch (animal.animalType) {
	case TYPE_ANIMAL::DOG:
		fileWriteStream << "dog";
		break;
	case TYPE_ANIMAL::CAT:
		fileWriteStream << "cat";
		break;
	case TYPE_ANIMAL::RABBIT:
		fileWriteStream << "rabbit";
		break;
	default:
		fileWriteStream << "unkown";
		break;
	}
	fileWriteStream << std::endl;

	fileWriteStream << animal.name << std::endl;
	fileWriteStream << animal.gender << std::endl;
	fileWriteStream << animal.age << std::endl;

	fileWriteStream.close();
}

void readInfoAboutAnimal(const char* filePath, Animal& animal) {
	/*type
	name
	age
	gender*/

	std::ifstream fileReadStream(filePath);

	if (!fileReadStream.is_open()) {
		std::cout << "Unseccsful file opening!" << std::endl;
		return;
	}

	char type[20];
	fileReadStream >> type;

	if (std::strcmp(type, "DOG") == 0) {
		animal.animalType = TYPE_ANIMAL::DOG;
	}
	else if (std::strcmp(type, "CAT") == 0) {
		animal.animalType = TYPE_ANIMAL::CAT;
	}
	else if (strcmp(type, "RABBIT") == 0) {
		animal.animalType = TYPE_ANIMAL::RABBIT;
	}
	else {
		animal.animalType = TYPE_ANIMAL::UNKNOWN;
	}

	fileReadStream >> animal.name;
	fileReadStream >> animal.age;
	fileReadStream >> animal.gender;

	fileReadStream.close();
}