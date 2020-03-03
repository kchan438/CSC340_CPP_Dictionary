///Kevin Chan
///SFSU ID: 918468621
///CSC-340 Programming Methodology Assignment 2 Part C - C++ Dictionary
///Spring 2020
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "readData.h"

using namespace std;

void readFile();
void searchInterface(string str);
void search(string str);

int main()
{
    readData readObj;
    readObj.readFile();
    //readFile();
    string searchWord;
    cout << "----- DICTIONARY 340 C++ -----\n" << endl;
    cout << "Search: ";
    cin >> searchWord;
    search(searchWord);
    //searchInterface(searchWord);
    //findWord(searchWord);
    //cout << "|\n";
    //while loop for searching dictionary
    //cout << "|\n";



    return 0;
}

void getInfo(ifstream file, vector<string> wordData) {
    string wordLine;
    string pos;
    string definition;

    getline(file, wordLine);


    /*while(getline(file,wordLine))
    {

    }*/
}

void searchInterface(string phrase)
{
    istringstream ss(phrase);
    vector<string> stringVector;
    for(string s; ss >> s;)
    {
        stringVector.push_back(s);
    }
    cout << " size " << stringVector.size();
    for(int i=0; i<stringVector.size(); i++)
    {
        cout << stringVector.at(i) << " ";
    }

}

void search(string phrase)
{
    // Used to split string around spaces.
    istringstream ss(phrase);
    vector<string> stringArr(3);
    int counter = 0;
    while(getline(ss,stringArr[counter], ' '))
    {
        counter++;
    }

    if(counter == 0 || counter > 3)
    {
        cout << "must be between 1 and 3 words" << endl;

    }

}
