
#ifndef People_h
#define People_h

#include <stdio.h>

#include<iostream>
#include <string>
#include"BST.h"

using namespace std;

template<class T>
class People{
private:
    string name;
    string bday;
    
public:
    People();
    People(string);
    
};

People<T>::People(ifstream& input){
    string line;
    string name;
    string bday;
    
    getline(input, line);
    
    size_t tab = line.find("\t");
    
    name = line.substr(0, tab);
    bday = line.substr(tab+1);
    
    this->bday = bday;
    this->name = name;
    
    while(!input.eof()){
        People* ptr;
        getline(input, line);
        ptr = new People(line);
        insertNewHero(ptr);
        
        
    }
    
}

People<T>::People(string line){
    
    string line, name, bday;
    
   size_t tab = line.find("\t");
   name = line.substr(0,tab);
   bday = line.substr(tab+1);
    
    
}

#endif /* People_h */
