#ifndef COMPUTER_PART_H
#define COMPUTER_PART_H

enum PartType
{
	UNKNOWN = -1,
	MONITOR = 0,
	COMPUTER,
	LAPTOP,
	MOUSE,
	KEYBOARD,
	HEADPHONES,
	CAMERA
};

#pragma once
class ComputerPart
{
private:
	PartType type;
	short warranty;
	double price;
	char* brand;
	char* model;

public:
	ComputerPart();
	ComputerPart(ComputerPart& other);
	ComputerPart(PartType type, short warranty, double price, char* brand, char* model);
	ComputerPart& operator=(const ComputerPart& other);
	~ComputerPart();

	void setPrice(const double price);

	PartType getType() const;
	short getWarranty() const;
	double getPrice() const;
	char* getBrand() const;
	char* getModel() const;

private:
	void setType(const PartType type);
	void setWarranty(const short warranty);
	void setBrand(const char* brand);
	void setModel(const char* model);

	void copy(const ComputerPart& other);
	void destroy();
};

#endif // !COMPUTER_PART_H
