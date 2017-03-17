#include<iostream>
#include"Vector3D.h"
using namespace std;

Vector3D operator - (Vector3D& v1, Vector3D& v2) {
	Vector3D result;
	result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

int main() {

	Vector3D a, b, c;

	char filename[32];
	cin >> filename;

	ifstream f;
	f.open(filename);

	a.read_from_file(f);
	b.read_from_file(f);
	c.read_from_file(f);

	// Vector3D d = a * 2 + b * 3 + c * (a * b);
	// d.print();
    
	f.close();

	return 0;
}