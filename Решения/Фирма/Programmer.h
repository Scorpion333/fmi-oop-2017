#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Programmer {
private:
	char* name;
	unsigned languages;
	unsigned salary;
public:
	Programmer() {
		name = new char[1];
		name[0] = '\0';
		languages = 0;
		salary = 0;
	}
	Programmer(char* _name, unsigned _languages, unsigned _salary) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		languages =  _languages;
		salary = _salary;
	}
	Programmer(const Programmer& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		languages = other.languages;
		salary = other.salary;
	}

	Programmer& operator = (const Programmer& other) {
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			languages = other.languages;
			salary = other.salary;
		}
    	return *this;
	}
	~Programmer() {
		delete[] name;
	}

	// SETTERS
	void set_name(char* _name) {
		delete[] name;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	void set_languages(unsigned _languages) {
		languages = _languages;
	}
	void set_salary(unsigned _salary) {
		salary = _salary;
	}

	// GETTERS
	const char* get_name() const {
		return name;
	}
	unsigned get_languages() const {
		return languages;
	}
	unsigned get_salary() const {
		return salary;
	}

	// INPUT AND OUTPUT
	void read() {
		cout << "name: ";      cin >> name;
		cout << "languages: "; cin >> languages;
		cout << "salary: ";    cin >> salary;
	}
	void print() {
		cout << "name: " << name << endl
			 << "languages: " << languages << endl
			 << "salary: " << salary << endl;
	}
	
	// OPERATORS
	bool operator < (Programmer other) {
		return languages < other.languages;
	}
	bool operator > (Programmer other) {
		return languages > other.languages;
	}
	bool knows_more_than(Programmer other) {
		return languages > other.languages;
	}
};