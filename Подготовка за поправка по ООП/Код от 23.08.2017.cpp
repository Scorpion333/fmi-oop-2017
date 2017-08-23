
// DEBUG NEEDED!

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

	// const

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
		if(_fn >= 100000 && _fn <= 999999)
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
			char* temp = new char[2 * capacity + 1];
			capacity *= 2;
			strcpy(temp, helper);
			delete[] helper;
			helper = temp;
		}
		helper[i] = in.get();
		i++;
	}
	helper[i] = '\0';
	in.get();

	st.setName(helper);
	in >> st.fn >> st.grade;
	return in;
}

ostream& operator << (ostream& out, const Student& st) {
	out << st.getName() << "\n"
		<< st.getFn() << "\n"
		<< st.getGrade();
	return out;
}

int main() {
	int capacity = 4;
	Student* students = new Student[capacity];
	int i = 0;

	ifstream in("students1.txt");
	
	while (!in.eof()) {
		if (i == capacity) {
			capacity *= 2;
			Student* temp = new Student[capacity];
			for (int j = 0; j < i; j++) {
				temp[j] = students[j];
			}
			delete[] students;
			students = temp;
		}
		in >> students[i];
		i++;
	}
	in.close();		// Optional

	ofstream out("students2.txt");

	int* seenFn = new int[i];
	int seenFnSize = 0;

	for (int j = 0; j < i; j++) {
		
		bool fnIsSeen = false;
		
		for (int k = 0; k < seenFnSize; k++) {
			if (seenFn[k] == students[j].getFn()) {
				fnIsSeen = true;
			}
		}
		
		if (!fnIsSeen) {
			double grade = 0;
			int count = 0;
			for (int k = 0; k < i; k++) {
				if (students[k].getFn() == students[j].getFn()) {
					grade += students[k].getGrade();
					count++;
				}
			}
			grade /= count;
			students[j].setGrade(grade);

			seenFn[seenFnSize] = students[j].getFn();
			seenFnSize++;

			out << students[j] << '\n';
		}
	}
	return 0;
}