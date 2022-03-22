// P01-PerfectJobOffer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#define PATH_FILE "offers.txt"
struct JobOffer {
	char name[26];
	int devCount;
	int paidHolidaysDays;
	long long payment;
};

void saveOffers(const char* filePath, size_t offersCount);
void filtersOffers(const char* filePath, long long minSalary);
bool existOffer(const char* filePath, long long minSalary);

void printOffer(const JobOffer& jobOffer);
void offerInitiliaze(JobOffer& jobOffer);

int main()
{
	unsigned int offersCount;
	std::cin >> offersCount;

	saveOffers(PATH_FILE, offersCount);
	filtersOffers(PATH_FILE, 10000);
}
#pragma region OfferFunctions
void saveOffers(const char* filePath, const size_t offersCount) {

	std::ofstream writeStream(filePath, std::ios::out | std::ios::binary);

	if (!writeStream.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}

	for (size_t offerIndex = 0; offerIndex < offersCount; offerIndex++) {
		JobOffer tempOffer;
		offerInitiliaze(tempOffer);
		writeStream.write((const char*)&tempOffer, sizeof(tempOffer));
		//writeStream.write((const char*)&tempOffer.name, sizeof(tempOffer.name));
		//writeStream.write((const char*)&tempOffer.devCount, sizeof(tempOffer.devCount));
		//writeStream.write((const char*)&tempOffer.paidHolidaysDays, sizeof(tempOffer.paidHolidaysDays));
		//writeStream.write((const char*)&tempOffer.payment, sizeof(tempOffer.payment));
	}

	writeStream.close();
}

void filtersOffers(const char* filePath, long long minSalary) {
	std::ifstream readStream(filePath, std::ios::binary);

	if (!readStream.is_open()) {
		std::cout << "Error!" << std::endl;
		return;
	}

	JobOffer tempOffer;

	while (readStream.read((char*)&tempOffer, sizeof(tempOffer))) {

		//readStream.read((char*)&tempOffer.name, sizeof(tempOffer.name));
		//readStream.read((char*)&tempOffer.devCount, sizeof(tempOffer.devCount));
		//readStream.read((char*)&tempOffer.paidHolidaysDays, sizeof(tempOffer.paidHolidaysDays));
		//readStream.read((char*)&tempOffer.payment, sizeof(tempOffer.payment));

		if (minSalary <= tempOffer.payment) {
			printOffer(tempOffer);
			std::cout << std::endl;
		}
	}

	readStream.close();
}

bool existOffer(const char* filePath, long long minSalary) {
	std::ifstream readStream(filePath, std::ios::binary);

	if (!readStream.is_open()) {
		std::cout << "Error!" << std::endl;
		return false;
	}

	JobOffer tempOffer;

	while (!readStream.eof()) {
		readStream.read((char*)&tempOffer, sizeof(tempOffer));

		//readStream.read((char*)&tempOffer.name, sizeof(tempOffer.name));
		//readStream.read((char*)&tempOffer.devCount, sizeof(tempOffer.devCount));
		//readStream.read((char*)&tempOffer.paidHolidaysDays, sizeof(tempOffer.paidHolidaysDays));
		//readStream.read((char*)&tempOffer.payment, sizeof(tempOffer.payment));

		if (minSalary <= tempOffer.payment) {
			return true;
		}
	}

	readStream.close();
	return false;
}

#pragma endregion

void printOffer(const JobOffer& jobOffer) {
	std::cout << "Corporation name: " << jobOffer.name << std::endl
		<< "Dev counts: " << jobOffer.devCount << std::endl
		<< "Paid holidays: " << jobOffer.paidHolidaysDays << std::endl
		<< "Payment per project: " << jobOffer.payment << std::endl;
}

void offerInitiliaze(JobOffer& jobOffer) {
	std::cout << "Corporation name: ";
	std::cin.ignore();
	std::cin.getline(jobOffer.name, 25);
	std::cout << "Dev counts: ";
	std::cin >> jobOffer.devCount;
	std::cout << "Paid holidays: ";
	std::cin >> jobOffer.paidHolidaysDays;
	std::cout << "Payment per project: ";
	std::cin >> jobOffer.payment;
}