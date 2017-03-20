#include "People.h"

People::People(string line) {
	string name;
	string bday;

	size_t tab = line.find('\t');

	name = line.substr(0, tab);
	bday = line.substr(tab + 1);

	this->bday = bday;
	this->name = name;
}

bool operator<(People & person1, People & person2) {
	return (person1.name < person2.name);
}

bool operator>(People & person1, People & person2) {
	return (person1.name > person2.name);
}

ostream & operator<<(ostream & os, People& person) {
	os << person.name << '\t' << person.bday << '\n';
	return os;
}
