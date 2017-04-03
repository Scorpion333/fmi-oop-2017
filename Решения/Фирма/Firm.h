#pragma once
#include<cstring>
#include"Programmer.h"
const unsigned MIN_CAPACITY = 32;

class Firm {
private:
	char* name;
	Programmer* employees;
	unsigned employees_number;
	unsigned capacity;

	void copy(const Firm& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		employees_number = other.employees_number;
		capacity = other.capacity;
		employees = new Programmer[capacity];
		for (unsigned i = 0; i < employees_number; i++) {
			employees[i] = other.employees[i];
		}
	}
public:
	// CONSTRUCTORS
	// We didn't discuss the 2nd one but it's a good idea too 
	Firm() {
		name = new char[1];
		name[0] = '\0';
		employees_number = 0;
		capacity = MIN_CAPACITY;
		employees = new Programmer[capacity];
	}
	Firm(char* _name, unsigned _capacity) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		employees_number = 0;
		capacity = _capacity;
		employees = new Programmer[capacity];
	}
	Firm(const Firm& other) {
		copy(other);
	}
	
	Firm& operator = (const Firm& other) {
		if (this != &other) {
			delete[] name;
			delete[] employees;
			copy(other);
		}
    	return *this;
	}
	~Firm() {
		delete[] name;
		delete[] employees;
	}
	
	// SETTERS AND GETTERS
	void set_name(char* _name) {
		delete[] name;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	const char* get_name() const {
		return name;
	}
	unsigned get_employees_number() const {
		return employees_number;
	}
	unsigned get_capacity() const {
		return capacity;
	}
	Programmer get_employee(unsigned i) const {
		return employees[i];
	}

	// METHODS FOR THE EMPLOYEES
	void hire(const Programmer& junior) {
		if (employees_number < capacity) {
			employees[employees_number] = junior;
			employees_number++;
		}
	}
	void fire_last(unsigned n) {
		employees_number -= n;
	}
	void print_employees() const {
		for (unsigned i = 0; i < employees_number; i++)
			employees[i].print();
	}
	const char* lucky_name() const {
		return employees[0].get_name();
	}
	unsigned salaries_sum() const {
		unsigned sum = 0;
		for (unsigned i = 0; i < employees_number; i++) {
			sum += employees[i].get_salary();
		}
		return sum;
	}
	
	// OPERATORS
	Firm operator + (const Firm& other) const {
		Firm sum(name, capacity + other.capacity);
		for (unsigned i = 0; i < employees_number; i++)
			sum.hire(employees[i]);
		for (unsigned i = 0; i < other.employees_number; i++)
			sum.hire(other.employees[i]);
		return sum;
	}
	bool operator > (const Firm& other) const {
		return salaries_sum() > other.salaries_sum();
	}
	bool operator < (const Firm& other) const {
		return salaries_sum() < other.salaries_sum();
	}
};