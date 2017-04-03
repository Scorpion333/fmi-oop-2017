#pragma once
#include"Item.h"
const unsigned MIN_CAPACITY = 32;

class OnlineStore {
private:
	Item* goods;
	unsigned size;
	unsigned capacity;
	
	void resize() {
		Item* temp = goods;
		capacity *= 2;
		goods = new Item[capacity];

		for (unsigned i = 0; i < size; i++) {
			goods[i] = temp[i];
		}
		delete[] temp;
	}
public: 
	OnlineStore() {
		capacity = MIN_CAPACITY;
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
	
	OnlineStore& operator = (const OnlineStore& other) {	
		if (this != &other) {		
			delete[] goods;
			size = other.size;
			capacity = other.capacity;
			goods = new Item[capacity];
			for (unsigned i = 0; i < size; i++) {
				goods[i] = other.goods[i];
			}
		}
        return *this;
	}
	~OnlineStore() {
		delete[] goods;
	}

	void add(const Item& new_item) {
		if (size >= capacity) {
			resize();
		}
		goods[size] = new_item;
		size++;
	}
};