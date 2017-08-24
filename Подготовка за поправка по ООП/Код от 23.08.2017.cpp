#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class Student {
	char* name;
	int fn;
	double grade;
public:
	Student() {
		name = new char[1];
		name[0] = '\0';
		fn = 0;
		grade = 0;
	}
	Student(const Student& other) {
		fn = other.fn;
		grade = other.grade;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	Student& operator = (const Student& other) {
		if (this != &other) {
			fn = other.fn;
			grade = other.grade;
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
		}
		return *this;
	}
	~Student() {
		delete[] name;
	}

	int getFn() const {
		return fn;
	}
	double getGrade() const {
		return grade;
	}
	const char* getName() const {
		return name;
	}

	void setFn(int _fn) {
		if (_fn >= 100000 && _fn <= 999999)
			fn = _fn;
	}
	void setGrade(double _grade) {
		grade = _grade;
	}
	void setName(const char* _name) {
		delete[] name;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	friend istream& operator >> (istream& in, Student& st);
};

istream& operator >> (istream& in, Student& st) {
	int capacity = 4;
	char* helper = new char[capacity + 1];
	int i = 0;

	while (in.peek() != ' ' && in.peek() != '\n' && !in.eof()) {
		if (i == capacity) {
			helper[i] = '\0';	// Strcpy needs this!
			capacity *= 2;
			char* temp = new char[capacity + 1];
			strcpy(temp, helper);
			delete[] helper;
			helper = temp;
		}
		helper[i] = in.get();
		i++;
	}
	helper[i] = '\0';

	st.setName(helper);
	delete[] helper;			// No memory leaks!

	in >> st.fn >> st.grade;

	in.ignore();					// Newline character after the grade also caused trouble.
	return in;
}

ostream& operator << (ostream& out, const Student& st) {
	out << st.getName() << "\n"
		<< st.getFn() << "\n"
		<< st.getGrade();
	return out;
}
