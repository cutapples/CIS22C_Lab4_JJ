#include<iostream>
#include<string>
#include<fstream>
#include"BST.h"

using namespace std;

int showOperations();
template <class T>
void checkChoice(int, BST<T> tree);
void closeProgram();

int main(){
    BST<string> tree;
    ifstream input;
    ofstream postOrderfile;
    ofstream breadthFirstFile;
    
    
    int choice = showOperations();
                 checkChoice(choice, tree);
    
}

int showOperations(){
   
    int choice;
    cout<<" Binary Search Tree Operations "<<endl;
    cout<<" ----------------------------- "<<endl;
    cout<<" 1. Insertion/Creation "<<endl;
    cout<<" 2. Post-Order Traversal "<<endl;
    cout<<" 3. Breadth-Order Transversal" << endl;
    cout<<" 4. Removal "<<endl;
    cout<<" 5. Exit "<<endl;
    cout<<" Enter your choice : ";
    cin >> choice;
    
    return choice;

}

template <class T>
void checkChoice(int choice, BST<T> tree){
    if(choice == 1){
        
    // call insertions function
    }
    
    else if(choice == 2){
        //call post order traversal function
    }
    
    else if(choice == 3){
        //call breadth order function
    }
    
    else if(choice == 4){
        //call remove function
    }
    
    else if(choice == 5){
        cout << "SEE YEA!\n";
    }
    
    
}
