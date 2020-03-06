///CSC-340-02
///Kevin Chan SFSU ID: 918468621
///Teammate: Yuhua Hui SFSU ID:
///Assignment Number: 02
///CSC-340 Programming Methodology Assignment 2 Part C - C++ Dictionary
///Spring 2020

#include <iostream>
#include <string>
#include "readData.h"
#include "Dictionary.h"

using namespace std;

int main()
{
    string string;
    Dictionary diction;
    diction.initialize();
    cout << "----- DICTIONARY 340 C++ -----" << endl;
    cout << "Search: ";
    getline(cin, string);
    transform(string.begin(),string.end(),string.begin(), ::tolower); //converts string into lowercase
    while(string!= "!q" || string!= "!Q")
    {
        diction.search(string);
    }
    return 0;
}

