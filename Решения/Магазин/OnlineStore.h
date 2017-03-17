#pragma once
#include"Item.h"

class OnlineStore {
	Item goods[128];
	unsigned size = 0;

public:
	void add(Item& new_item) {
		if (size >= 128)
			return;

		goods[size] = new_item;
		size++;
	}
};