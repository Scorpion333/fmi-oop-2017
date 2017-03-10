#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Vector3D {
	double x;
	double y;
	double z;
public:
	void set_x(double _x) {
		x = _x;
	}
	double get_x() {
		return x;
	}
	void set_y(double _y) {
		y = _y;
	}
	double get_y() {
		return y;
	}
	void set_z(double _z) {
		z = _z;
	}
	double get_z() {
		return z;
	}

	Vector3D operator + (Vector3D other) {
		Vector3D result;
		result.x = x + other.x;
		result.y = y + other.y;
		result.z = z + other.z;
		return result;
	}
	double operator * (Vector3D other) {
		return x * other.x + y * other.y + z * other.z;
	}
	Vector3D operator * (double n) {
		Vector3D result;
		result.x = x * n;
		result.y = y * n;
		result.z = z * n;
		return result;
	}

	void print() {
		cout << "(" << x << "," << y << "," << z << ")";
	}

	void read_from_file(char* filename) {
		ifstream in;
		in.open(filename);
		char temp[8];
		in >> temp;
		x = temp[1] - '0';
		y = temp[3] - '0';
		z = temp[5] - '0';
		in.close();
	}
	void write_in_file(char* filename) {
		ofstream out;
		out.open(filename);	
		out << "(" << x << "," << y << "," << z << ")";
		out.close();
	}
	
	void read_from_file(ifstream& in) {
		char temp[8];
		in >> temp;

		x = temp[1] - '0';
		y = temp[3] - '0';
		z = temp[5] - '0';
	}
};