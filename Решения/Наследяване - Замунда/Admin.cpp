#pragma once
#include<iostream>
#include<string>

#include"DynamicArray.h"
#include"Admin.h"
#include"Banana.h"

using std::cin;
using std::cout;
using std::string;


Admin::Admin(const string& _username, const string& _password) : Uploader(_username, _password) {}

string Admin::rank() {
	return "Admin";
}

void Admin::remove_banana(DynamicArray<Banana*>& bananas_in_zamunda) {
	string removed_name;
	cout << "Enter banana name: ";
	cin >> removed_name;
	for (unsigned i = 0; i < bananas_in_zamunda.get_size(); i++) {
		if (bananas_in_zamunda[i]->get_name() == removed_name) {
			bananas_in_zamunda.remove_by_index(i);
			cout << "Removed sucessfully.\n";
			return;
		}
	}
	cout << "Invalid banana name.\n";
}

void Admin::register_user(DynamicArray<User*>& users) {
	string name, password, rank;
	
	cout << "Enter new user's username: ";
	cin >> name;
	cout << "Enter new user's password: ";
	cin >> password;
	cout << "Enter new user's rank: ";
	cin >> rank;

	if (rank == "User") {
		users.push_back(new User(name, password));
		cout << "Registration was successful.\n";
	}
	else if (rank == "Uploader") {
		users.push_back(new Uploader(name, password));
		cout << "Registration was successful.\n";
	}
	else if (rank == "Admin") {
		users.push_back(new Admin(name, password));
		cout << "Registration was successful.\n";
	}
	else {
		cout << "Invalid user rank.\n";
	}		
}