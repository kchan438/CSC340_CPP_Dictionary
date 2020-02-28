///Kevin Chan
///SFSU ID: 918468621
///CSC-340 Programming Methodology Assignment 2 Part C - C++ Dictionary
///Spring 2020
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readFile();

using namespace std;

int main()
{

    readFile();
    

    return 0;
}


void readFile()
{

    fstream fileIO;
    string line;
    cout << "! Opening data file.. ./Data.CS.SFSU.txt" << endl;
    fileIO.open("../Assignment-02-Code Files/Data.CS.SFSU.txt");

    if(fileIO.fail())
    {
        cout << "File not found." << endl;
        exit(0);
    }

    /*while(getline(fileIO, line))
    {
        cout << line << endl;
    }*/
}

void getInfo(ifstream file, string line, vector<string> wordData)
{
    
}