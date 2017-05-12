#include<iostream>
#include<string>
#include<fstream>
using std::cin;
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

struct Student {
	unsigned fn;
	string first_name;
	string last_name;
};

// Task 3
void copy_file(char* file_name_1, char* file_name_2) {
	ifstream in(file_name_1);
	ofstream out(file_name_2);

	char sym;
	while (in.peek() != EOF) {
		sym = in.get();
		out << sym;
	}
	in.close();
	out.close();
}

// Task 1
int main() {
	
	ifstream in("students.txt");
	
	unsigned n;
	in >> n;
	
	Student* arr = new Student[n];

	for (unsigned i = 0; i < n; i++) {
		in >> arr[i].fn >> arr[i].first_name >> arr[i].last_name;
	}

	unsigned index_of_min = 0;
	for (unsigned i = 1; i < n; i++) {
		if (arr[i].fn < arr[index_of_min].fn)
			index_of_min = i;
	}
	cout << arr[index_of_min].first_name << " " << arr[index_of_min].last_name << '\n';
	
	return 0;
}