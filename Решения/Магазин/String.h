#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class String {
private:
	char* arr;

public:
	// CONSTRUCTORS
	String() {
		arr = new char[2];
		arr[0] = 'X';
		arr[1] = '\0';
	}
	String(const char* _arr) {
		arr = new char[strlen(_arr) + 1];
		strcpy(arr, _arr);
	}
	String(const String& other) {
		arr = new char[strlen(other.arr) + 1];
		strcpy(arr, other.arr);
	}
	
	// OPERATORS =
	// We can write a second operator = with char*
	String& operator = (const String& other) {
        if(this != &other) {
            delete[] arr;
            arr = new char[strlen(other.arr) + 1];
            strcpy(arr, other.arr);
        }
        return *this;
    }
    String& operator = (char* _arr) {
        if(this != &other) {
            delete[] arr;
            arr = new char[strlen(_arr) + 1];
            strcpy(arr, _arr);
        }
        return *this;
    }
	
	// DESTRUCTOR
	~String() {
		delete[] arr;
	}

	// OTHER METHODS
	unsigned length() const {
		return strlen(arr);
	}
	bool operator == (const String& other) const {
		return strcmp(arr, other.arr) == 0;
	}

	// FRIENDZONE
	friend ostream& operator << (ostream& out, const String& str);
};

istream& operator >> (istream& in, String& str) {
	char temp[100];
	in >> temp;
	str = temp;
	return in;
}
ostream& operator << (ostream& out, const String& str) {
	out << str.arr;
	return out;
}