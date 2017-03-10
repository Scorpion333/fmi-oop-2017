#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Programmer {
private:
	char name[20];
	unsigned languages;
	unsigned salary;
public:
	// SETTERS
	void set_name(char* _name) {
		strcpy(name, _name);
	}
	void set_languages(unsigned _languages) {
		languages = _languages;
	}
	void set_salary(unsigned _salary) {
		salary = _salary;
	}

	// GETTERS
	char* get_name() {
		char* result;
		result = new char[strlen(name) + 1];
		strcpy(result, name);
		return result;
	}
	unsigned get_languages() {
		return languages;
	}
	unsigned get_salary() {
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