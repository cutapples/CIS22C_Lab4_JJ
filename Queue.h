#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "SLinkedList.h"
#include "HeaderNode.h"
using namespace std;

template <class T>
class Queue : protected SLinkedList<T> {
public:

	void enqueue(T& data);
	T dequeue();
	void front();
	bool isEmpty();
};

template <class T>
void Queue<T>::enqueue(T& data) {
	this->addBack(data);
}

template <class T>
T Queue<T>::dequeue() {
	T* tempData = this->list->front->data;
	this->removeFront();
	return *tempData;
}

template <class T>
void Queue<T>::front() {
	if (this->list->count > 0) {
		cout << *this->list->front->data;
	}
}

template <class T>
bool Queue<T>::isEmpty() {
	return (this->list->front == nullptr);
}

#endif QUEUE_H