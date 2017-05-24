#pragma once
#include"Question.h"
#include<iostream>
using std::cin;
using std::cout;

class YesNoQuestion : public Question {
	bool correct_answer;
	bool user_answer;
	unsigned points;
public:
	YesNoQuestion(string _description, bool _correct_answer, unsigned _points) {
		description = _description;
		correct_answer = _correct_answer;
		points = _points;
	}
	void ask() {
		cout << description;
		cin >> user_answer;
	}
	unsigned grade() {
		if (user_answer == correct_answer)
			return points;
		else
			return 0;
	}
};