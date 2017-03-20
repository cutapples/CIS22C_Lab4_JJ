#include "Database.h"

Database::Database() {
	saveFile.open("SaveFile.txt");
	if (saveFile.fail()) {
		saveFile.close();
		saveFile.open("SaveFile.txt", fstream::out | fstream::in);
		saveFile.close();
		saveFile.open("SaveFile.txt");
	}

	saveFile.seekg(0);
	while (!saveFile.eof()) {
		People* tempPtr = nullptr;
		string line;
		getline(saveFile, line);
		if (line != "") {
			tempPtr = new People(line);
			addItem(*tempPtr);
		}
	}
	saveFile.clear();
}

void Database::addItem(People & data) {
	binarySearchTree.insert(data, binarySearchTree.getRoot());
}

void Database::addItem(string name, string bday) {
	string line = name + '\t' + bday;
	People* tempPtr = new People(line);
	binarySearchTree.insert(*tempPtr, binarySearchTree.getRoot());
}

void Database::removeItem(string name) {
	name += "\t ";
	People tempData(name);
	binarySearchTree.remove(tempData, binarySearchTree.getRoot());
}

void Database::printPostOrder() {
	remove("PostOrder.txt");
	outputFile.open("PostOrder.txt");
	if (outputFile.fail()) {
		outputFile.close();
		outputFile.open("PostOrder.txt", fstream::out);
	}
	binarySearchTree.printPostOrder(outputFile, binarySearchTree.getRoot());
	outputFile.close();
}

void Database::printInOrder() {
	remove("InOrder.txt");
	outputFile.open("InOrder.txt");
	if (outputFile.fail()) {
		outputFile.close();
		outputFile.open("InOrder.txt", fstream::out);
	}
	binarySearchTree.printInOrder(outputFile, binarySearchTree.getRoot());
	outputFile.close();
}

void Database::printBreadthFirst() {
	remove("BreadthFirst.txt");
	outputFile.open("BreadthFirst.txt");
	if (outputFile.fail()) {
		outputFile.close();
		outputFile.open("BreadthFirst.txt", fstream::out);
	}
	binarySearchTree.printBreadthFirst(outputFile);
	outputFile.close();
}

void Database::saveToFile(fstream & saveFile) {
	saveFile.close();
	remove("SaveFile.txt");
	saveFile.open("SaveFile.txt");
	if (saveFile.fail()) {
		saveFile.close();
		saveFile.open("SaveFile.txt", fstream::out);
	}
	binarySearchTree.printBreadthFirst(saveFile);
	saveFile.clear();
}

Database::~Database() {
	saveToFile(saveFile);
	saveFile.close();
	if (outputFile.is_open()) {
		outputFile.close();
	}
}
