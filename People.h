#ifndef People_h
#define People_h

#include <stdio.h>

#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

class People {
private:
	string name;
	string bday;

public:
	People(string);

	friend bool operator<(People& person1, People& person2);
	friend bool operator>(People& person1, People& person2);
	friend ostream& operator<<(ostream& os, People& person);
};

#endif People_h