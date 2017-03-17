#pragma once
#include<cstring>
#include"Programmer"

class Firm {
private:
	char* name;
	Programmer* employees;
	unsigned employees_number;
	unsigned capacity;
public:
	void initialize(char* _name, unsigned _capacity) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		capacity = _capacity;
		employees = new Programmer[capacity];
		employees_number = 0;
	}
	void clear_memory() {
		delete[] name;
		delete[] employees;
	}

	// SETTERS AND GETTERS
	void set_name(char* _name) {
		delete[] name;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	char* get_name() {
		char* result = new char[strlen(name) + 1];
		strcpy(result, name);
		return result;
	}
	unsigned get_employees_number() {
		return employees_number;
	}
	unsigned get_capacity() {
		return capacity;
	}
	Programmer get_employee(unsigned i) {
		return employees[i];
	}

	// METHODS FOR THE EMPLOYEES
	void hire(Programmer junior) {
		if (employees_number < capacity) {
			employees[employees_number] = junior;
			employees_number++;
		}
	}
	void fire_last(unsigned n) {
		employees_number -= n;
	}
	void print_employees() {
		for (unsigned i = 0; i < employees_number; i++)
			employees[i].print();
	}
	char* lucky_name() {
		char* result = new char[strlen(employees[0].get_name()) + 1];
		strcpy(result, employees[0].get_name());
		return result;
	}

	// OPERATORS
	Firm operator + (Firm other) {
		Firm sum;
		sum.initialize(name, capacity + other.capacity);
		for (unsigned i = 0; i < employees_number; i++)
			sum.hire(employees[i]);
		for (unsigned i = 0; i < other.employees_number; i++)
			sum.hire(other.employees[i]);
		return sum;
	}
	unsigned salaries_sum() {
		unsigned sum = 0;
		for (unsigned i = 0; i < employees_number; i++) {
			sum += employees[i].get_salary();
		}
		return sum;
	}
	bool operator > (Firm other) {
		return salaries_sum() > other.salaries_sum();
	}
	bool operator < (Firm other) {
		return salaries_sum() < other.salaries_sum();
	}
};