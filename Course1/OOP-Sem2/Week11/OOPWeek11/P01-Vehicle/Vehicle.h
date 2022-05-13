#ifndef VEHICLE_H
#define VEHICLE_

enum Color {
	UNKNOWN = -1,
	RED,
	BLACK,
	BLUE,
	GREEN,
	COUNT
};

#pragma once 
#pragma warning(disable : 4996 )

class Vehicle
{
protected:
	Color _color;
	char* _brand;
	size_t _prodYear;
	size_t _seatsCount;
	size_t _maxSpeed;
public:
	Vehicle();
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	~Vehicle();

	void setColor(const Color color);
	void setBrand(const char* brand);
	void setProdYear(const size_t prodYear);
	void setSeatsCount(const size_t seatsCount);
	void setMaxSpeed(const size_t maxSpeed);

	Color getColor();
	const char* getBrand()const;
	size_t getProdYear();
	size_t getSeatsCount();
	size_t getMaxSpeed();
private:
	void destroy();
	void copy(const Vehicle& other);
};

#endif // !VEHICLE_H