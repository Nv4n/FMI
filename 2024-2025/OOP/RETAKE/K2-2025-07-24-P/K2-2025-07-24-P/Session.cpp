#include "Session.h"

Session::Session(char name[3], char date[8], Article** materials, unsigned duration)
{
}

Session::Session(const Session& other)
{
}

Session& Session::operator=(const Session& other)
{
}

Session::~Session()
{
	clearMem();
}

void Session::copy(const Session& other)
{
	for (size_t i = 0; i < NAME_LENGTH; i++)
	{
		name[i] = other.name[i];
	}
	for (size_t i = 0; i < DATE_LENGTH; i++)
	{
		date[i] = other.date[i];
	}
	duration = other.duration;
	materialsLength = other.materialsLength;
	materialsCapacity = other.materialsCapacity;
	materials = new Article * [materialsCapacity];
	for (size_t i = 0; i < materialsLength; i++)
	{
		materials[i] = other.materials[i]->clone();
	}
}

void Session::clearMem() {
	for (size_t i = 0; i < materialsLength; i++)
	{
		delete materials[i];
	}
	delete[] materials;
}

void Session::extendMaterialsMem()
{
	materialsCapacity *= 2;
	Article** temp=new Article*[materialsCapacity];
	for (size_t i = 0; i < materialsLength; i++)
	{
		temp[i] = materials[i];
	}
	delete[] materials;
	materials = temp;
}
