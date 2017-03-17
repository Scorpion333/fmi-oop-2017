#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class String {
private:
	char arr[32];

public:
	void set_symbol(unsigned index, char sym) {
		arr[index] = sym;
	}
	char get_symbol(unsigned index) {
		return arr[index];
	}
	
	unsigned length() {
		return strlen(arr);
	}
	bool operator == (String& other) {
		return strcmp(arr, other.arr) == 0;
	}

	friend istream& operator >> (istream& in, String& str);
	friend ostream& operator << (ostream& out, String& str);
};

istream& operator >> (istream& in, String& str) {
	in >> str.arr;
	return in;
}

ostream& operator << (ostream& out, String& str) {
	out << str.arr;
	return out;
}