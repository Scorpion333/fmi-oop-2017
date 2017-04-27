#pragma once
#include"Uploader.h"

class Admin : public Uploader {
public:
	Admin(const string& _username = "", const string& _password = "");
	string rank();
	void remove_banana(DynamicArray<Banana*>& bananas_in_zamunda);
	void register_user(DynamicArray<User*>& users);
};