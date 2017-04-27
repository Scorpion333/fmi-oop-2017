#pragma once
#include<string>
#include"DynamicArray.h"
using std::string;

class Banana;

class User {
	string username;
	string password;
	unsigned downloaded;
	unsigned uploaded;
	DynamicArray<Banana*> bananas;
public:
	User(const string& _username = "", const string& _password = "");
    
	bool match(const string& _username, const string& _password);
	bool match(const string& _username);
	
	double rating();
	void download(Banana* banana);
	void seed(unsigned megabytes);
	void delete_banana(const string& banana_name);
    
	virtual string rank();
    
	virtual void upload(DynamicArray<Banana*>& bananas_in_zamunda);
	virtual void remove_banana(DynamicArray<Banana*>& bananas_in_zamunda);
	virtual void register_user(DynamicArray<User*>& users);
};
