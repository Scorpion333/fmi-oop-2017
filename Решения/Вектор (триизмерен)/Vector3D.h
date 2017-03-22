#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Vector3D {
	double x;
	double y;
	double z;

public:
	// SETTERS AND GETTERS
	void set_x(double _x) {
		x = _x;
	}
	void set_y(double _y) {
		y = _y;
	}
	void set_z(double _z) {
		z = _z;
	}
    
	double get_x() const {
		return x;
	}
	double get_y() const {
		return y;
	}
	double get_z() const {
		return z;
	}

	// OPERATORS DEFINED AS METHODS
	Vector3D operator + (const Vector3D& other) {
		Vector3D result;
		result.x = x + other.x;
		result.y = y + other.y;
		result.z = z + other.z;
		return result;
	}
	double operator * (const Vector3D& other) {
		return x * other.x + y * other.y + z * other.z;
	}
	Vector3D operator * (double n) {
		Vector3D result;
		result.x = x * n;
		result.y = y * n;
		result.z = z * n;
		return result;
	}

	// FRIENDZONE
	friend Vector3D operator - (const Vector3D& v1, const Vector3D& v2);

	friend istream& operator >> (istream& in, Vector3D& v);
	friend ostream& operator << (ostream& out, const Vector3D& v);
};

istream& operator >> (istream& in, Vector3D& v) {
	in.get();
	in >> v.x;
	in.get();
	in >> v.y;
	in.get();
	in >> v.z;
	in.get();
	in.get();
	return in;
}

ostream& operator << (ostream& out, const Vector3D& v) {
	out << "(" << v.x << "," << v.y << "," << v.z << ")";
	return out;
}