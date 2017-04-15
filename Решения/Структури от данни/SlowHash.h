#pragma once
#include"DynamicArray.h"

template<typename KeyT, typename ValueT>
class SlowHash {
	DynamicArray<KeyT> keys;
	DynamicArray<ValueT> values;

public:

	void add(const KeyT& key, const ValueT& value) {
		for(unsigned i = 0; i < keys.get_size(); i++) {
			if (keys[i] == key) {
				values[i] = value;
				return;
			}
		}
		keys.push_back(key);
		values.push_back(value);
	}
	bool has_key() const {
		for (unsigned i = 0; i < keys.get_size(); i++) {
			if (keys[i] == key) {
				return true;
			}
		}
		return false;
	}

	ValueT get_value(const KeyT& key) const {
		for (unsigned i = 0; i < keys.get_size(); i++) {
			if (keys[i] == key) {
				return values[i];
			}
		}
	}

	ValueT operator [] (const KeyT& key) const {
		return get_value(key);
	}
	
	ValueT& operator [] (const KeyT& key) {
		for (unsigned i = 0; i < keys.get_size(); i++) {
			if (keys[i] == key) {
				return values[i];
			}
		}
		keys.push_back(key);
		values.push_back(ValueT());
		return values[values.get_size() - 1];
	}
};