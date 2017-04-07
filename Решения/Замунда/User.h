#pragma once
#include<iostream>
#include<string>
#include"DynamicArray.h"
#include"Banana.h"
using namespace std;

class User {
	string username;
	string password;
	unsigned downloaded;
	unsigned uploaded;
	DynamicArray<Banana*> bananas;
public:
	User(string _username = "", string _password = "") {
		username = _username;
		password = _password;
		downloaded = 0;
		uploaded = 0;
		bananas = DynamicArray<Banana*>();
	}
    
	bool match(string _username, string _password) {
		return username == _username && password == _password;
	}
	bool match(string _username) {
		return username == _username;
	}
	
	double rating() {
		if (downloaded == 0) {
			return 0;
		}
		return double(uploaded) / double(downloaded);
	}

	void download(Banana* banana) {
		downloaded += banana->get_size();
		bananas.push_back(banana);
		banana->be_downloaded_by(this);
	}
    
    // I initially named this method "upload" but
    // "seed" is a better name for "letting someone else download information from you"
	void seed(unsigned megabytes) {
		uploaded += megabytes;
	}
    
	void delete_banana(string banana_name) {
		for (unsigned i = 0; i < bananas.get_size(); i++) {
			if (bananas[i]->get_name() == banana_name) {
				bananas.remove_by_index(i);
				return;
			}
		}
	}
    
    // There are better ideas for this method
    // but I wanted to make things simpler
	virtual string rank() {
		return "User";
	}
};
