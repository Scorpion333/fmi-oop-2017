#include<iostream>
#include"Vector3D.h"
using namespace std;

Vector3D operator - (const Vector3D& v1, const Vector3D& v2) {
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

	f >> a >> b >> c;

	Vector3D d = a * 2 + b * 3 + c * (a * b);
	cout << d << '\n';
    
	f.close();

	return 0;
}