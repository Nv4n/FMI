//
// Created by Sybatron on 5/18/2024.
//

#ifndef OOP_ELECTRICALAPPLIANCE_H
#define OOP_ELECTRICALAPPLIANCE_H
class Room;

class ElectricalAppliance {
protected:
    Room* room;
    char* brand;
    char* model;
    char* serialNumber;
    double consumedPower;
    bool isRunning;
public:
    ElectricalAppliance(char *brand, char *model, char *serialNumber, double consumedPower);

    virtual ~ElectricalAppliance();

    void setIsRunning(bool isRunning);

};


#endif //OOP_ELECTRICALAPPLIANCE_H
