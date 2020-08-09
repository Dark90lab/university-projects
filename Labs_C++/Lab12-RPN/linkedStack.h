#pragma once
#include <iostream>
#include "stackADT.h"
#include "linkedQueue.h"
using namespace std;


template <typename T = int>
class linkedStack : public stackADT<T>, private linkedQueue<T>
{
private:
	int stackSize;
	const int MAX_STACK_SIZE = 100;
public:
	linkedStack();
	void initializeStack();
	bool isEmptyStack() const;
	void push(const T& newItem);
	T top() const;
	void pop();
};

template <typename T>
linkedStack<T>::linkedStack() : linkedStack<T>::linkedQueue(), stackSize(0) {}

template <typename T>
void linkedStack<T>::initializeStack() {
	linkedStack<T>::initializeQueue();
	stackSize = 0;
}

template <typename T>
bool linkedStack<T>::isEmptyStack() const {
	return linkedStack<T>::isEmptyQueue();
}

template <typename T>
void linkedStack<T>::push(const T& newItem) {
	if (stackSize < MAX_STACK_SIZE) {
		linkedStack<T>::addQueueFront(newItem);
		stackSize++;
	}
}

template <typename T>
T linkedStack<T>::top() const {
	return linkedStack<T>::front();
}

template <typename T>
void linkedStack<T>::pop() {
	stackSize--;
	linkedStack<T>::deleteQueue();
}