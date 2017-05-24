#pragma once
#include"Question.h"
#include<iostream>
using std::cin;
using std::cout;

const unsigned MAX_ANSWERS = 10;

class MultipleChoiceQuestion : public Question {
	string possible_answers[MAX_ANSWERS];
	unsigned answers_number;
	unsigned points_per_answer;
	bool right_answers[MAX_ANSWERS];
	bool user_answers[MAX_ANSWERS];
public:
	MultipleChoiceQuestion(string* _possible_answers,
		unsigned _answers_number, unsigned _points_per_answer,
		bool* _right_answers) {
		answers_number = _answers_number;
		points_per_answer = _points_per_answer;
		for (unsigned i = 0; i < answers_number; i++) {
			possible_answers[i] = _possible_answers[i];
			right_answers[i] = _right_answers[i];
		}
	}

	void ask() {
		cout << description;
		for (unsigned i = 0; i < answers_number; i++) {
			cin >> user_answers[i];
		}
	}
	unsigned grade() {
		unsigned points = 0;
		for (unsigned i = 0; i < answers_number; i++) {
			if (user_answers[i] == right_answers[i])
				points += points_per_answer;
		}
		return points;
	}
};