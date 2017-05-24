#pragma once
const unsigned MIN_CAPACITY = 16;

template<typename T>
using map_fn = void(*)(T&);

template<typename T>
using predicate = bool(*)(const T&);

// R - Result type, E - element type
template<typename R, typename E>
using reduce_fn = R(*)(const R&, const E&);

template<typename T>
class DynamicArray {
private:
	T* arr;
	unsigned size;
	unsigned capacity;

	void resize();
	void copy(const DynamicArray<T>& other);
public:
	DynamicArray();
	DynamicArray(const DynamicArray<T>& other);
	DynamicArray<T>& operator = (const DynamicArray<T>& other);
	~DynamicArray();
	
	void push_back(const T& new_element);
	
	T& operator [] (unsigned i);
	T operator[](unsigned i) const;

	unsigned get_size() const;

	void remove_by_index(unsigned index);

	void map(map_fn<T> func);

	void filter(predicate<T> pred);

	template<typename ResultType>
	ResultType reduce(const ResultType& start_value, reduce_fn<ResultType, T> func);
};



template<typename T>
void DynamicArray<T>::resize() {
	capacity *= 2;
	T* temp = new T[capacity];
	for (unsigned i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

template<typename T>
void DynamicArray<T>::copy(const DynamicArray<T>& other) {
	size = other.size;
	capacity = other.capacity;
	arr = new T[capacity];
	for (unsigned i = 0; i < size; i++) {
		arr[i] = other.arr[i];
	}
}

template<typename T>
DynamicArray<T>::DynamicArray() {
	size = 0;
	capacity = MIN_CAPACITY;
	arr = new T[capacity];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
	copy(other);
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator = (const DynamicArray<T>& other) {
	if (this != &other) {
		delete[] arr;
		copy(other);
	}
	return *this;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] arr;
}

template<typename T>
void DynamicArray<T>::push_back(const T& new_element) {
	if (size == capacity) {
		resize();
	}
	arr[size] = new_element;
	size++;
}

template<typename T>
T& DynamicArray<T>::operator [] (unsigned i) {
	return arr[i];
}
	
template<typename T>
T DynamicArray<T>::operator[](unsigned i) const {
	return arr[i];
}

template<typename T>
unsigned DynamicArray<T>::get_size() const {
	return size;
}

template<typename T>
void DynamicArray<T>::remove_by_index(unsigned index) {
	for (unsigned i = index; i <= size - 2; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
}

template<typename T>
void DynamicArray<T>::map(map_fn<T> func) {
	for (unsigned i = 0; i < size; i++) {
		func(arr[i]);
	}
}

template<typename T>
void DynamicArray<T>::filter(predicate<T> pred) {
	for (unsigned i = 0; i < size; i++) {
		if (!pred(arr[i])) {
			remove_by_index(i);
		}
	}
}

template<typename T>
template<typename ResultType>
ResultType DynamicArray<T>::reduce(const ResultType& start_value, reduce_fn<ResultType, T> func) {
	ResultType accumulated = start_value;
	for (unsigned i = 0; i < size; i++) {
		accumulated = func(accumulated, arr[i]);
	}
	return accumulated;
}