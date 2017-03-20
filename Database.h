#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>

#include "BST.h"
#include "People.h"

using namespace std;

class Database {
private:
	BST<People> binarySearchTree;
	fstream saveFile;
	fstream outputFile;

public:
	Database();

	void addItem(People& data);
	void addItem(string name, string bday);
	void removeItem(string name);
	void printPostOrder();
	void printInOrder();
	void printBreadthFirst();

	void saveToFile(fstream& saveFile);

	~Database();
};



#endif DATABASE_H