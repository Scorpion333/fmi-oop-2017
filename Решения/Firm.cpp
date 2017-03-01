#include<iostream>
#include<cstring>
using namespace std;

struct Programmer
{
	char name[20];
	unsigned languages;
	unsigned salary;

	void read()
	{
		cout << "name: ";      cin >> name;
		cout << "languages: "; cin >> languages;
		cout << "salary: ";    cin >> salary;
	}
	void print()
	{
		cout << "name: "      << name      << endl
			 << "languages: " << languages << endl
			 << "salary: "    << salary    << endl;
	}
	bool correctData()
	{
		return languages > 0 && salary > 0;
	}
	bool knowsMoreThan(Programmer other)
	{
		return languages > other.languages;
	}
};

class Firm
{
private:
	char* name;
	Programmer* employees;
	unsigned employees_number;
	unsigned capacity;
public:
	void initialize(char* _name, unsigned _capacity)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		capacity = _capacity;
		employees = new Programmer[capacity];
		employees_number = 0;
	}
	void hire(Programmer junior)
	{
		if (employees_number < capacity)
		{
			employees[employees_number] = junior;
			employees_number++;
		}
	}
	void fire_last(unsigned n)
	{
		employees_number -= n;
	}
	void print_employees()
	{
		for (unsigned i = 0; i < employees_number; i++)
			employees[i].print();
	}
	char* lucky_name()
	{
		char* result = new char[strlen(employees[0].name) + 1];
		strcpy(result, employees[0].name);
		return result;
	}
	void clear_memory()
	{
		delete[] name;
		delete[] employees;
	}
};

int main()
{
	return 0;
}