#include<iostream>
#include<fstream>
#include"Item.h"
#include"OnlineStore.h"
using namespace std;

int main() {
	
	OnlineStore store;

	ifstream in;
	in.open("StoreInfo.txt");
	
	unsigned goods_number;
	in >> goods_number;

	Item current_item;

	for (unsigned i = 0; i < goods_number; i++) {

		// We still haven't written this operator.
		// in >> current_item;
		store.add(current_item);
	}

	return 0;
}