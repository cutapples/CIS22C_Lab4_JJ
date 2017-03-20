#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include <vector>
#include "BSTNode.h"
#include "Queue.h"

using namespace std;

template <class T>
class BST {
private:
	BSTNode<T>* root;

public:
	BST();
	~BST();

	bool isEmpty();
	BSTNode<T>* getRoot();

	void insert(T& data, BSTNode<T>* node);
	void remove(T data, BSTNode<T>* node);
	bool search(T data, BSTNode<T>* node);
	void clear(BSTNode<T>* node);

	void printPostOrder(fstream& os, BSTNode<T>* node);
	void printInOrder(fstream& os, BSTNode<T>* node);
	void printBreadthFirst(fstream& os);
};

template <class T>
BST<T>::BST() {
	this->root = nullptr;
}

template <class T>
BST<T>::~BST() {
	clear(root);
}

template <class T>
bool BST<T>::isEmpty() {
	return (this->root == nullptr);
}

template <class T>
BSTNode<T>* BST<T>::getRoot() {
	return this->root;
}

template <class T>
void BST<T>::insert(T& data, BSTNode<T>* node) {
	if (isEmpty()) {
		this->root = new BSTNode<T>(data);
		return;
	}
	else {
		if (data < *node->data) {
			if (node->leftChild != nullptr) {
				insert(data, node->leftChild);
			}
			else {
				node->leftChild = new BSTNode<T>(data);
			}
		}
		else {
			if (node->rightChild != nullptr) {
				insert(data, node->rightChild);
			}
			else {
				node->rightChild = new BSTNode<T>(data);
			}
		}
	}
}

template <class T>
void BST<T>::remove(T data, BSTNode<T>* node) {
	//Case if empty tree
	if (node == nullptr) {
		return;
	}
	//Case if less than
	else if (data < *node->data) {
		remove(data, node->leftChild);
	}
	//Case if greater than
	else if (data > *node->data) {
		remove(data, node->rightChild);
	}
	//Case if found
	else {
		if (node->leftChild == nullptr && node->leftChild == nullptr) {
			delete node->data;
			delete node;
		}
		else if (node->leftChild == nullptr) {
			BSTNode<T>* tempPtr = node->rightChild;
			while (tempPtr->leftChild != nullptr) {
				tempPtr = tempPtr->leftChild;
			}
			T* tempData = node->data;
			node->data = tempPtr->data;
			delete tempData;
			delete tempPtr;
		}
		else {
			BSTNode<T>* tempPtr = node->leftChild;
			while (tempPtr->rightChild != nullptr) {
				tempPtr = tempPtr->rightChild;
			}
			T* tempData = node->data;
			node->data = tempPtr->data;
			delete tempData;
			delete tempPtr;
		}
	}
}

template <class T>
bool BST<T>::search(T data, BSTNode<T>* node) {
	if (node == nullptr) {
		return false;
	}
	else if (data < *node->data) {
		search(data, node->leftChild);
	}
	else if (data > *node->data) {
		search(data, node->rightChild);
	}
	else {
		return true;
	}
}

template <class T>
void BST<T>::clear(BSTNode<T>* node) {
	if (node != nullptr) {
		clear(node->leftChild);
		clear(node->rightChild);
		delete node->data;
		delete node;
	}
}

template <class T>
void BST<T>::printPostOrder(fstream& os, BSTNode<T>* node) {
	if (node != nullptr) {
		printPostOrder(os, node->leftChild);
		printPostOrder(os, node->rightChild);
		cout << *node->data;
		os << *node->data;
	}
}

template<class T>
void BST<T>::printInOrder(fstream & os, BSTNode<T>* node) {
	if (node != nullptr) {
		printInOrder(os, node->leftChild);
		cout << *node->data;
		os << *node->data;
		printInOrder(os, node->rightChild);
	}
}

template <class T>
void BST<T>::printBreadthFirst(fstream& os) {
	Queue<BSTNode<T>*> nodeQueue;
	BSTNode<T>* currentNode = this->root;
	while (currentNode != nullptr) {
		cout << *currentNode->data;
		os << *currentNode->data;
		if (currentNode->leftChild != nullptr) {
			nodeQueue.enqueue(currentNode->leftChild);
		}
		if (currentNode->rightChild != nullptr) {
			nodeQueue.enqueue(currentNode->rightChild);
		}
		if (!nodeQueue.isEmpty()) {
			currentNode = nodeQueue.dequeue();
		}
		else {
			currentNode = nullptr;
		}
	}
	os.clear();
}

#endif BST_H