#ifndef DEVICE_H
#define DEVICE_H

#pragma once
#pragma warning(disable:4996)
class Device
{
protected:
	char* _model;
	char* _brand;
	size_t _price;

public:
	Device() = delete;
	Device(const Device& other);
	Device& operator=(const Device& other);
	~Device();
	virtual Device* clone() = 0;

	const char* getModel()const;
	const char* getBrand()const;

	//TODO I/O
	virtual void print() = 0;
	virtual void write(std::ofstream& os, const Device& obj) = 0;
	virtual void read(const std::ifstream& is, Device& obj) = 0;

protected:
	void copy(const Device& other);
private:
	void destroy();
};

#endif // !DEVICE_H