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
		in >> current_item;
		store.add(current_item);
	}
	double bill = 0;
	unsigned order_size;
	
	in.close();
	in.open("Order.txt");

	in >> order_size;

	for (unsigned i = 0; i < order_size; i++) {
		// ...
	}
	// ...

	return 0;
}