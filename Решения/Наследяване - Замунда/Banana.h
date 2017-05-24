#pragma once
#include<string>
#include"DynamicArray.h"
using std::string;

class User;

class Banana {
	string name;
	unsigned size;
	DynamicArray<User*> seeders;
public:
	Banana(const string& _name, unsigned _size);
	string get_name();
	unsigned get_size();
	void be_downloaded_by(User* user);
};
