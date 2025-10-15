#include "Engine.h"
#include<cstring>

Engine::Engine() :volume(0),
power(0),
cylinder(0),
fuelType(FuelType::UNKNOWN),
model(nullptr) {}

Engine::Engine(Engine& other) {
	copy(other);
}

Engine::Engine(double volume, short power, short cylinder, FuelType fuelType, char* model) {
}

Engine::Engine(Engine&& other) {

}
Engine& Engine::operator=(const Engine& other) {

}
Engine& Engine::operator=(Engine&& other) {

}
Engine::~Engine() {
	delete[] model;
}


void Engine::setVolume(double volume) {
	this->volume = volume;
}
double Engine::getVolume() {
	return volume;
}


void Engine::setPower(short power) {
	this->power = power;
}
short Engine::getPower() {
	return power;
}

void Engine::setCylinder(short cylinder) {
	this->cylinder = cylinder;
}
short Engine::getCylinder() {
	return cylinder;
}

void Engine::setFuelType(FuelType fuelType) {
	this->fuelType = fuelType;
}
FuelType Engine::getFuelType() {
	return fuelType;
}

void Engine::setModel(char* model) {
	delete[] model;
	this->model = new char[std::strlen(model)];
	std::strcpy(this->model, model);
}
char* Engine::getModel() {
	return model;
}

void Engine::copy(Engine& other) {
	setVolume(other.getVolume());
	setPower(other.getPower());
	setCylinder(other.getCylinder());
	setModel(other.getModel());
	setFuelType(other.getFuelType());
}