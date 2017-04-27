#pragma once

#include<iostream>
#include<string>

#include"DynamicArray.h"
#include"User.h"
#include"Banana.h"

using std::string;
using std::cout;


User::User(const string& _username, const string& _password)
    : username(_username), password(_password), downloaded(0), uploaded(0), bananas() {}
    
bool User::match(const string& _username, const string& _password) {
	return username == _username && password == _password;
}
bool User::match(const string& _username) {
	return username == _username;
}
	
double User::rating() {
	if (downloaded == 0) {
		return 0;
	}
	return double(uploaded) / double(downloaded);
}

void User::download(Banana* banana) {
	downloaded += banana->get_size();
	bananas.push_back(banana);
	banana->be_downloaded_by(this);
}
    
void User::seed(unsigned megabytes) {
	uploaded += megabytes;
}
    
void User::delete_banana(const string& banana_name) {
	for (unsigned i = 0; i < bananas.get_size(); i++) {
		if (bananas[i]->get_name() == banana_name) {
			bananas.remove_by_index(i);
			return;
		}
	}
}
    
string User::rank() {
	return "User";
}

void User::upload(DynamicArray<Banana*>& bananas_in_zamunda) {
	cout << "Permission denied! Only uploaders and admins can upload bananas.\n";
}
void User::remove_banana(DynamicArray<Banana*>& bananas_in_zamunda) {
	cout << "Permission denied! Only admins can remove bananas.\n";
}
void User::register_user(DynamicArray<User*>& users) {
	cout << "Permission denied! Only admins can register users.\n";
}