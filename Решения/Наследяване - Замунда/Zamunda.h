#pragma once
#include"DynamicArray.h"
#include"User.h"
#include"Banana.h"

class Zamunda {
	DynamicArray<User*> users;
	DynamicArray<Banana*> bananas;
	User* current_user;
public:
	Zamunda();
	~Zamunda();

	void login();
	void logout();
	void download();
	void upload();
	void remove_banana();	
	void register_user();
};
