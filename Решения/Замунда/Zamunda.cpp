#pragma once

#include<iostream>

#include"DynamicArray.h"
#include"User.h"
#include"Admin.h"
#include"Banana.h"
#include"Zamunda.h"

using std::cin;
using std::cout;
using std::string;


Zamunda::Zamunda() : users(), bananas(), current_user(NULL) {
	users.push_back(new Admin("founder", "founder"));
}
Zamunda::~Zamunda() {
	for (unsigned i = 0; i < users.get_size(); i++) {
		delete users[i];
	}
	for (unsigned i = 0; i < bananas.get_size(); i++) {
		delete bananas[i];
	}
}

void Zamunda::login() {
	if (current_user != NULL) {
		cout << "There is logged user.\n";
	}
	else {
		string username, password;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;
		
		for (unsigned i = 0; i < users.get_size(); i++) {
			if (users[i]->match(username)) {
				if (users[i]->match(username, password)) {
					current_user = users[i];
					cout << "Logged successfully.\n";
				}
				else {
					cout << "Incorrect name or password.\n";
				}
				return;
			}
		}
		cout << "Incorrect name or password.\n";
	}
}
	
void Zamunda::logout() {
	if (current_user == NULL) {
		cout << "No one is logged.\n";
	}
	else {
		current_user = NULL;
		cout << "Logged out successfully.\n";
	}
}

void Zamunda::download() {
	if (current_user == NULL) {
		cout << "Permission denied! Only logged users can download.\n";
		return;
	}
	string entered_name;
	cout << "Enter banana name: ";
	cin >> entered_name;

	for (unsigned i = 0; i < bananas.get_size(); i++) {
		if (bananas[i]->get_name() == entered_name) {
			current_user->download(bananas[i]);
			cout << "Banana downloaded successfully.\n";
			return;
		}
	}
	cout << "Invalid banana name.\n";
}

void Zamunda::upload() {
	if (current_user == NULL) {
		cout << "Permission denied! Only logged uploaders and admins can upload.\n";
		return;
	}
	current_user->upload(bananas);
}
	
void Zamunda::remove_banana() {
	if (current_user == NULL) {
		cout << "Permission denied! Only logged admins can remove bananas.\n";
		return;
	}
	current_user->remove_banana(bananas);
}

void Zamunda::register_user() {
	if (current_user == NULL) {
		cout << "Permission denied! Only logged admins can register users.\n";
		return;
	}
	current_user->register_user(users);
}