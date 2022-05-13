#ifndef PHONE_H
#define PHONE_H

#include "Device.h"

enum SecurityLockType {
	UNKNOWN = -1,
	FACE,
	FINGERPRINT,
	COUNT
};

#pragma once
#pragma warning(disable:4996)
class Phone :public Device
{
private:
	size_t _camerasCount;
	SecurityLockType _secLockType;

public:

private:
	void copy(const Phone& other);
};

#endif // !PHONE_H
