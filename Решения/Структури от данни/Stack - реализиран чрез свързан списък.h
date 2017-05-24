#ifndef STACK_H
#define STACK_H

template<typename T>
struct Box {
    T data;
    Box<T>* next;
}

template<typename T>
class Stack {
	Box<T>* start;
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
	start = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
	while(!empty()) {
        pop();
    }
}

template<typename T>
bool Stack<T>::empty() const {
	return start == nullptr;
}

template<typename T>
void Stack<T>::push(const T& new_element) {
	Box<T>* old_start = start;
    start = new Box<T>;
    start->data = new_element;
    start->next = old_start;
}

// Undefined behavior if the stack is empty
template<typename T>
void Stack<T>::pop() {
	Box<T>* old_start = start;
    start = start->next;
    delete old_start;
}

// Undefined behavior if the stack is empty
template<typename T>
T Stack<T>::top() const {
	return start->data;
}

#endif