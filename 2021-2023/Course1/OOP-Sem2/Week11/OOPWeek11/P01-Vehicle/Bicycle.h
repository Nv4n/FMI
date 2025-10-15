#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"

#pragma once
class Bicycle:public Vehicle
{
private:
	size_t _speedsCount;
	size_t _lightRflrsCount;
	bool _hasBell;

};
#endif // !BICYCLE_H

