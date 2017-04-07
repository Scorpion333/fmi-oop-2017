#pragma once
#include"User.h"

class Uploader : public User {
public:
	string rank() {
		return "Uploader";
	}
};