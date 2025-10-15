//
// Created by Sybatron on 5/18/2024.
//

#include "ElectricalAppliance.h"

void ElectricalAppliance::setIsRunning(bool isRunning) {
    ElectricalAppliance::isRunning = isRunning;
}

ElectricalAppliance::ElectricalAppliance(char *brand, char *model, char *serialNumber, double consumedPower) : brand(
        brand), model(model), serialNumber(serialNumber), consumedPower(consumedPower) {}

ElectricalAppliance::~ElectricalAppliance() {
    delete[]brand;
    delete[]model;
    delete[]serialNumber;
}
