#pragma once
const unsigned MIN_CAPACITY = 16;

template<typename T>
class DynamicArray {
private:
	T* arr;
	unsigned size;
	unsigned capacity;

	void resize() {
		capacity *= 2;
		T* temp = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	void copy(const DynamicArray<T>& other) {
		size = other.size;
		capacity = other.capacity;
		arr = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
public:
	DynamicArray() {
		size = 0;
		capacity = MIN_CAPACITY;
		arr = new T[capacity];
	}
	DynamicArray(const DynamicArray<T>& other) {
		copy(other);
	}
	DynamicArray& operator = (const DynamicArray<T>& other) {
		if (this != &other) {
			delete[] arr;
			copy(other);
		}
		return *this;
	}
	~DynamicArray() {
		delete[] arr;
	}
	
	void push_back(const T& new_element) {
		if (size == capacity) {
			resize();
		}
		arr[size] = new_element;
		size++;
	}
	
	T& operator [] (unsigned i) {
		return arr[i];
	}
	T operator[](unsigned i) const {
		return arr[i];
	}

	unsigned get_size() const {
		return size;
	}

	void remove_by_index(unsigned index) {
		for (unsigned i = index; i <= size - 2; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
};