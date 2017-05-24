#include"Commander.h"

/*
Commander::Commander() {
	Knight();
	capacity = 100;
	subs_number = 0;
	subs = new Knight[capacity];
}
Commander::Commander(const Commander& other) {
	Knight(other);
	capacity = other.capacity;
	subs_number = other.subs_number;
	subs = new Knight[capacity];
	for (unsigned i = 0; i < subs_number; i++) {
		subs[i] = other.subs[i];
	}
}*/

Commander::Commander() : Knight(), capacity(100), subs_number(0) {
	subs = new Knight[capacity];
}

Commander::Commander(const Commander& other)
	: Knight(other), capacity(other.capacity),
	subs_number(other.subs_number),
	subs(new Knight[capacity]) {
	
	for (unsigned i = 0; i < subs_number; i++) {
		subs[i] = other.subs[i];
	}
}

Commander& Commander::operator = (const Commander& other) {
	if (this != &other) {
		Knight::operator=(other);
		delete[] subs;
		capacity = other.capacity;
		subs_number = other.subs_number;
		subs = new Knight[capacity];
		for (unsigned i = 0; i < subs_number; i++) {
			subs[i] = other.subs[i];
		}
	}
	return *this;
}

Commander::~Commander() {
	delete[] subs;
}