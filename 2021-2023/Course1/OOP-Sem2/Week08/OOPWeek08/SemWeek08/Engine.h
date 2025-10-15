#ifndef STRING_ENGINE_N
#define STRING_ENGINE_N

#include <cstdlib>
#include<cstring>
#include<stdexcept>

enum class FuelType {
	UNKNOWN = -1,
	DIESEL,
	PETROL,
	EL
};

#pragma once
class Engine
{
private:
	double volume;
	short power;
	short cylinder;
	FuelType fuelType;
	char* model;

public:
	Engine();
	Engine(Engine& other);
	Engine(double volume, short power, short cylinder, FuelType fuelType, char* model);
	Engine(Engine&& other);
	Engine& operator=(const Engine& other);
	Engine& operator=(Engine&& other);
	~Engine();

	void setVolume(double volume);
	void setPower(short power);
	void setCylinder(short cylinder);
	void setFuelType(FuelType fuelType);
	void setModel(char* model);

	double getVolume();
	short getPower();
	short getCylinder();
	FuelType getFuelType();
	char* getModel();

	//static void boom() {
	//	throw new std::out_of_range("Err");
	//}

private:
	void copy(Engine& other);
};

#endif //!STRING_ENGINE_N




