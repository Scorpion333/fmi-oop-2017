#pragma once

#include<string>

#include"DynamicArray.h"
#include"Banana.h"
#include"User.h"

using std::string;


Banana::Banana(const string& _name, unsigned _size) : name(_name), size(_size), seeders() {}

string Banana::get_name() {
	return name;
}

unsigned Banana::get_size() {
	return size;
}

void Banana::be_downloaded_by(User* user) {
	for (unsigned i = 0; i < seeders.get_size(); i++) {
		seeders[i]->seed(size / seeders.get_size());
	}
	seeders.push_back(user);
}