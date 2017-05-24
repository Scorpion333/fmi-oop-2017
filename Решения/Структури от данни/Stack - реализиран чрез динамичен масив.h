#ifndef STACK_H
#define STACK_H

const size_t DEFAULT_CAPACITY = 16;

template<typename T>
class Stack {
	T* arr;
	size_t size;
	size_t capacity;
	void resize();
public:
	Stack();
	~Stack();
	bool empty() const;
	void push(const T& new_element);
	void pop();
	T top() const;
};

template<typename T>
Stack<T>::Stack() {
	size = 0;
	capacity = DEFAULT_CAPACITY;
	arr = new T[capacity];
}

template<typename T>
Stack<T>::~Stack() {
	delete[] arr;
}

template<typename T>
bool Stack<T>::empty() const {
	return size == 0;
}

template<typename T>
void Stack<T>::push(const T& new_element) {
	if (size >= capacity) {
		resize();
	}
	arr[size] = new_element;
	size++;
}

template<typename T>
void Stack<T>::resize() {
	capacity *= 2;
	T* temp = new T[capacity];
	for (unsigned i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

// Undefined behavior if the stack is empty
template<typename T>
void Stack<T>::pop() {
	size--;
}

// Undefined behavior if the stack is empty
template<typename T>
T Stack<T>::top() const {
	return arr[size - 1];
}

#endif