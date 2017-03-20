#ifndef BSTNODE_H
#define BSTNODE_H

template <class T>
class BSTNode {
public:
	T* data;
	BSTNode<T>* leftChild;
	BSTNode<T>* rightChild;
	BSTNode(T& data) { this->data = &data; leftChild = nullptr; rightChild = nullptr; };
};

#endif BSTNODE_H