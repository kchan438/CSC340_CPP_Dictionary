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
    Dictionary diction;
    diction.initialize();
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

//Get input from search
void Dictionary::getInputFromConsole(){
    std::cout << "----- DICTIONARY 340 C++ -----" << std::endl;
    while(true){
        std::cout << "Search: ";
        std::string s;
        getline(std::cin, s);

        //Then print out the result while parsing the message
        //print(parse(s));
    }
}
