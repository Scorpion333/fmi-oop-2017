#include<iostream>
#include"Vector3D.h"
using namespace std;

int main() {

	Vector3D a, b, c;

	char filename[32];
	cin >> filename;

	ifstream f;
	f.open(filename);

	a.read_from_file(f);
	b.read_from_file(f);
	c.read_from_file(f);

	Vector3D d = a * 2 + b * 3 + c * (a * b);

	d.print();
    
    f.close();

	return 0;
}