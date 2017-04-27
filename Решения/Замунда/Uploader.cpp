#pragma once
#include<iostream>
#include<string>
#include"DynamicArray.h"
#include"Uploader.h"
#include"Banana.h"
using std::cin;
using std::cout;
using std::string;

Uploader::Uploader(const string& _username, const string& _password) : User(_username, _password) {}

string Uploader::rank() {
	return "Uploader";
}
	
void Uploader::upload(DynamicArray<Banana*>& bananas_in_zamunda) {
	string new_banana_name;
	unsigned new_banana_size;
	cout << "Enter banana name: ";
	cin >> new_banana_name;
	cout << "Enter banana size: ";
	cin >> new_banana_size;
	Banana* new_banana = new Banana(new_banana_name, new_banana_size);
	bananas_in_zamunda.push_back(new_banana);
	cout << "Uploaded successfully.\n";
}
