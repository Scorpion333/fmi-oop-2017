#pragma once
#include<iostream>
#include<string>
using namespace std;

class Banana {
	string name;
	unsigned size;
	DynamicArray<User*> seeders;
public:
	string get_name() {
		return name;
	}
	unsigned get_size() {
		return size;
	}
	void be_downloaded_by(User* user) {
		for (unsigned i = 0; i < seeders.get_size(); i++) {
			seeders[i]->upload(size / seeders.get_size());
		}
		seeders.push_back(user);
	}
};
