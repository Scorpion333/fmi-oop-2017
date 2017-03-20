#pragma once
#include"Item.h"

class OnlineStore {
private:
	Item* goods;
	unsigned size;
	unsigned capacity;

public: 
	OnlineStore() {
		capacity = 32;
		goods = new Item[capacity];
		size = 0;
	}
	OnlineStore(unsigned _capacity) {
		capacity = _capacity;
		goods = new Item[capacity];
		size = 0;
	}
	OnlineStore(const OnlineStore& other) {
		size = other.size;
		capacity = other.capacity;
		goods = new Item[capacity];
		for (unsigned i = 0; i < size; i++) {
			goods[i] = other.goods[i];
		}
	}
	
	void operator = (const OnlineStore& other) {
		
		delete[] goods;

		size = other.size;
		capacity = other.capacity;
		goods = new Item[capacity];
		
		for (unsigned i = 0; i < size; i++) {
			goods[i] = other.goods[i];
		}
	}

	~OnlineStore() {
		delete[] goods;
	}

	void add(const Item& new_item) {
		if (size >= capacity) {
			return;
		}
		goods[size] = new_item;
		size++;
	}
};