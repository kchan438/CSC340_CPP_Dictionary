///CSC-340-02
///Kevin Chan SFSU ID: 918468621
///Teammate: Yuhua Hui SFSU ID:
///Assignment Number: 02
///CSC-340 Programming Methodology Assignment 2 Part C - C++ Dictionary
///Spring 2020

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "readData.h"
#include "Dictionary.h"

using namespace std;

int main()
{
    string string;
    Dictionary diction;
    diction.initialize();
    cout << "search: ";
    getline(cin, string);
    diction.search(string);
    //string searchWord;
    //cout << "----- DICTIONARY 340 C++ -----\n" << endl;
    //cout << "Search: ";
    //cin >> searchWord;
    //search(searchWord);
    //searchInterface(searchWord);
    //findWord(searchWord);
    //cout << "|\n";
    //while loop for searching dictionary
    //cout << "|\n";



    return 0;
}

