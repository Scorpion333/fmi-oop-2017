#pragma once
#include"Knight.h"

class Commander : public Knight {
	Knight* subs;
	unsigned subs_number;
	unsigned capacity;
public:
	Commander();
	Commander(const Commander& other);
	Commander& operator = (const Commander& other);
	~Commander();
};