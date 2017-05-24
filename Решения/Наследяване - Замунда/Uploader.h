#pragma once
#include"User.h"

class Uploader : public User {
public:
	Uploader(const string& _username = "", const string& _password = "");
	string rank();
	void upload(DynamicArray<Banana*>& bananas_in_zamunda);
};