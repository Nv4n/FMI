// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdexcept>
#include<fstream>
#include "ComputerStore.h"
#include "ComputerStoreWriter.h"
#include "ComputerPart.h"
#include "Configuration.h"
#include "ComputerPartWriter.h"

int main()
{
	size_t size;
	std::cin >> size;
	char* def = new char[size + 1];
	std::cin.ignore();
	std::cin.getline(def, size);

	//ComputerStore store(def, "11:00-22:30", 50.3, nullptr, 0, 10);
	ComputerPart part(PartType::CAMERA, 10, 50.5, "Slamsung", "11-CP");
	//store.addPart(part, 20);
	std::ofstream os("./Store.txt", std::ios::out | std::ios::trunc);
	ComputerPartWriter(os, part);

	try {
		Configuration config();
	}
	catch (std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
		return 0;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 0;
	}
}