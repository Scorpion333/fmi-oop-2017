#pragma once
#include<iostream>
#include<fstream>
#include"String.h"
using namespace std;

class Item {
private:
	String name;
	unsigned quantity;
	double price;

public:
	Item() {
		name = String();
		quantity = 0;
		price = 0;
	}
	Item(const String& _name, unsigned _quantity, double _price) {
		name = _name;
		quantity = _quantity;
		price = _price;
	}
	Item(const Item& other) {
		name = other.name;
		quantity = other.quantity;
		price = other.price;
	}
	Item& operator = (const Item& other) {
		name = other.name;
		quantity = other.quantity;
		price = other.price;
        return *this;
	}

	friend istream& operator >> (istream& in, Item& item);
	friend ostream& operator << (ostream& out, const Item& item);
};

istream& operator >> (istream& in, Item& item) {
	in >> item.name >> item.quantity >> item.price;
	return in;
}
ostream& operator << (ostream& out, const Item& item) {
	out << item.name << " " << item.quantity << " " << item.price;
	return out;
}