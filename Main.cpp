#include<iostream>
#include<string>
#include<fstream>
#include"Database.h"

using namespace std;

int showOperations();
void checkChoice(int, Database& database);

int main() {
	Database database;
	int choice;
	do {
		system("cls");
		choice = showOperations();
		checkChoice(choice, database);
	} while (choice > 0 && choice < 6);

}

int showOperations() {

	int choice;
	cout << " Binary Search Tree Operations " << endl;
	cout << " ----------------------------- " << endl;
	cout << " 1. Insertion/Creation " << endl;
	cout << " 2. In-Order Traversal" << endl;
	cout << " 3. Post-Order Traversal " << endl;
	cout << " 4. Breadth-First Transversal" << endl;
	cout << " 5. Removal " << endl;
	cout << " 6. Exit " << endl;
	cout << " Enter your choice : ";
	cin >> choice;

	return choice;

}

void checkChoice(int choice, Database& database) {
	if (choice == 1) {
		// call insertions function
		string name, bday;
		cout << "Please enter a name: ";
		cin >> name;
		cout << "Please enter a birthday: ";
		cin.ignore();
		getline(cin, bday);
		database.addItem(name, bday);
	}

	else if (choice == 2) {
		//call post order traversal function
		database.printInOrder();
		system("pause");
	}

	else if (choice == 3) {
		//call post order traversal function
		database.printPostOrder();
		system("pause");
	}

	else if (choice == 4) {
		//call breadth first function
		database.printBreadthFirst();
		system("pause");
	}

	else if (choice == 5) {
		//call remove function
		string name;
		cout << "Please enter a name you would like to remove from the BST: ";
		cin >> name;
		database.removeItem(name);
	}

	else if (choice == 6) {
		cout << "SEE YEA!\n";
	}


}