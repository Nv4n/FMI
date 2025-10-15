#include "Phone.h"

void Phone::copy(const Phone& other) {
	Device::copy(other);
	_camerasCount = other._camerasCount;
	_secLockType = other._secLockType;
}
