#pragma once
#include<string>
using std::string;

class Question {
protected:
	string description;
public:
	virtual void ask() = 0;
	virtual unsigned grade() = 0;
};