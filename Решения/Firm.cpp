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

int main() {
	return 0;
}