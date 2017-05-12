#include<cstring>
#include<fstream>
#include"String.h"

void String::copy(const char* _arr) {
	arr = new char[strlen(_arr) + 1];
	strcpy(arr, _arr);
}

String::String() {
	copy("");
}
String::String(const char* _arr) {
	copy(_arr);
}
String::String(const String& other) {
	copy(other.arr);
}

String& String::operator = (const String& other) {
	if (this != &other) {
		delete[] arr;
		copy(other.arr);
	}
	return *this;
}
	
String& String::operator = (const char* _arr) {
	if (arr != _arr) {		// The 2 pointers should not point to the same address
		delete[] arr;
		copy(_arr);
	}
	return *this;
}

String::~String() {
	delete[] arr;
}

unsigned String::length() const {
	return strlen(arr);
}
bool String::operator == (const String& other) const {
	return strcmp(arr, other.arr) == 0;
}
const char* String::c_str() const {
	return arr;
}

// Helper function - the best place to put it is in the CPP file where it is used
bool is_empty_char(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\t';
}

std::istream& operator >> (std::istream& in, String& str) {

	unsigned capacity = 16;
	char* temp = new char[capacity];

	// The "empty" characters in the beginning are ignored
	while (is_empty_char(in.peek())) {
		in.get();
	}

	// We read the string till the end of file or a new empty character
	unsigned i_temp = 0;
	while (!in.eof() && !is_empty_char(in.peek())) {
		temp[i_temp] = in.get();
		i_temp++;

		// Resize when necessarry
		if (i_temp == capacity) {
			capacity *= 2;
			char* helper = new char[capacity];
			for (unsigned j = 0; j < i_temp; j++) {
				helper[j] = temp[j];
			}
			delete[] temp;
			temp = helper;
		}
	}
	temp[i_temp] = '\0';

	// Ok, because we have String::operator=(const char*)
	str = temp;

	return in;
}

std::ostream& operator << (std::ostream& out, const String& str) {
	out << str.arr;
	return out;
}