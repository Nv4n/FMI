#pragma once
class Reminder
{
	//появи напомнянето, символен низ за заглавие, символен низ за бележки към
	//напомнянето, цяло неотрицателно число, което представлява приоритет.
private:
	char date[11]; //YYYY-MM-DD
	char* title;
	char** notes;
	size_t priority;
	size_t size;
	size_t capacity;
public:
	Reminder() = delete;
	Reminder(char date[10], const char* title, size_t priority);
	Reminder(const Reminder& other);
	Reminder(const Reminder&& other);
	Reminder& operator=(const Reminder& other);
	Reminder& operator=(const Reminder&& other);
	~Reminder();

	bool operator>(const Reminder& other)const;
	bool operator>=(const Reminder& other)const;
	bool operator<(const Reminder& other)const;
	bool operator<=(const Reminder& other)const;
	bool operator==(const Reminder& other)const;

	friend void operator>>(const std::istream& is, const Reminder& other);
	friend void operator<<(const std::ostream& os, const Reminder& other);

	void addNotes(const char* note);
private:
	void copy(const Reminder& other);
	void destroy();
	void resize();
};

