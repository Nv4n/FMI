#include <iostream>

enum Subject {
	UNKNOWN = -1,
	OOP,
	FPR,
	GEOMETRY,
	DIS2,
	SUBJECTS_COUNT
};

struct Student {
	char name[24];
	char egn[10];
	int facultyNumber;
	double grades[Subject::SUBJECTS_COUNT];
	Subject favouriteSubject;
};

struct Classroom {
	Student students[20];
	int studentsCount;
};

#pragma region DeclarationOfStudentFunctions
void initialize(Student& stud);
void print(const Student& stud);
void printAverageMarks(const Student* students, size_t count);
const Student& getBestStudent(const Student* students, size_t count);
void setFavouriteSubject(Student* students, size_t count);
#pragma endregion

void initialize(Classroom& classroom);
Subject getHardestSubject(const Classroom& classroom);
void printSubject(Subject);

double getAverageMarks(const double* grades);
void printSubjects();

int main() {
	Student students[3];
	for (int i = 0; i < 3; i++) {
		initialize(students[i]);
	}
	printAverageMarks(students, 3);

	setFavouriteSubject(students, 3);
	print(getBestStudent(students, 3));

	Classroom classroom;
	classroom.studentsCount = 3;
	for (int i = 0; i < classroom.studentsCount; i++) {
		classroom.students[i] = students[i];
	}
	return 0;
}

#pragma region StudentsFunctions
void initialize(Student& stud) {
	std::cout << "Name: ";
	std::cin >> stud.name;
	std::cout << "EGN: ";
	std::cin >> stud.egn;
	std::cout << "Factulty Number: ";
	std::cin >> stud.facultyNumber;

	std::cout << "Grades: ";
	for (int i = 0; i < SUBJECTS_COUNT; i++) {
		std::cin >> stud.grades[i];
	}
}

void print(const Student& stud) {
	std::cout << "Name: " << stud.name << std::endl
		<< "EGN: " << stud.egn << std::endl
		<< "Faculty Number: " << stud.facultyNumber << std::endl
		<< "Grades: ";
	for (int i = 0; i < SUBJECTS_COUNT; i++) {
		std::cout << stud.grades[i] << " ";
	}
	std::cout << std::endl << stud.favouriteSubject << std::endl;
}

void printAverageMarks(const Student* students, size_t count) {
	for (int i = 0; i < count; i++) {
		std::cout << students[i].name << " has average of: "
			<< getAverageMarks(students[i].grades) << std::endl;
	}
}

const Student& getBestStudent(const Student* students, size_t count) {
	double bestAvgMarks = 0;
	int bestStudentIndex = 0;

	for (int i = 0; i < count; i++) {
		double currentAverageMarks = getAverageMarks(students[i].grades);
		if (bestAvgMarks < currentAverageMarks)
		{
			bestStudentIndex = i;
			bestAvgMarks = currentAverageMarks;
		}
	}

	return students[bestStudentIndex];
}

void setFavouriteSubject(Student* students, size_t count) {
	for (int i = 0; i < count; i++) {
		int subject;
		printSubjects();
		std::cin >> subject;
		if (subject > UNKNOWN && subject < SUBJECTS_COUNT) {
			students[i].favouriteSubject = (Subject)subject;
		}
		else {
			i--;
		}
	}
}
#pragma endregion

#pragma region ClassroomFunctions
void initialize(Classroom& classroom) {
	std::cout << "Students' count: ";
	std::cin >> classroom.studentsCount;
	for (int i = 0; i < classroom.studentsCount; i++) {
		initialize(classroom.students[i]);
	}
}

Subject getHardestSubject(const Classroom& classroom) {
	double currentWorstMarksSum = 7;
	int worstSubjectIndex = 0;
	for (int subjectIndex = 0; subjectIndex < SUBJECTS_COUNT; subjectIndex++) {
		double currentMarksSum = 0;
		for (int studentIndex = 0; studentIndex < classroom.studentsCount; studentIndex++) {
			currentMarksSum += classroom.students[studentIndex].grades[subjectIndex];
		}

		if (currentWorstMarksSum / classroom.studentsCount > currentMarksSum / classroom.studentsCount) {
			currentWorstMarksSum = currentMarksSum;
			worstSubjectIndex = subjectIndex;
		}
	}

	return (Subject)worstSubjectIndex;
}

void printSubject(Subject subject) {
	switch (subject) {
	case 0:
		std::cout << "OOP" << std::endl;
		break;
	case 1:
		std::cout << "FPR" << std::endl;
		break;
	case 2:
		std::cout << "GEOMETRY" << std::endl;
		break;
	case 3:
		std::cout << "DIS2" << std::endl;
		break;
	}
}
#pragma endregion


double getAverageMarks(const double* grades) {
	double sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += grades[i];
	}
	return sum / 4;
}
void printSubjects() {
	std::cout << "0) OOP" << std::endl
		<< "1)FPR" << std::endl
		<< "2) GEOMETRY"
		<< "3) DIS2" << std::endl;
}