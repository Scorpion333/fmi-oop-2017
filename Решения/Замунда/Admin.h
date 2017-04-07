#pragma once
#include"User.h"

class Admin : public User {
public:
	string rank() {
		return "Admin";
	}
};