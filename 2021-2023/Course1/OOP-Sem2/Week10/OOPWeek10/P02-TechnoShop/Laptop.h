#ifndef LAPTOP_H
#define LAPTOP_H

#include "Device.h"
enum OS {
	UNKNOWN = -1,
	MACOS,
	LINUX,
	WINDOWS,
	COUNT
};

enum PortsType {
	UNKNOWN = -1,
	USB,
	THUNDERBOLT,
	COUNT
};

#pragma once
class Laptop :public Device
{
private:
	OS _os;
	PortsType _portsType;
	size_t _portsCount;
};

#endif // !LAPTOP_H