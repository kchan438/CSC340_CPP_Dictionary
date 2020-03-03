//
// Created by Kevin Chan on 3/2/20.
//

#include "readData.h"
#include <iostream>
#include <fstream>
using namespace std;

readData::readData() = default; //constructor

void readData::readFile()
{

    fstream fileIO;
    string line;
    string pos;
    string defintion;

    cout << "! Opening data file.. ./Data.CS.SFSU.txt" << endl;
    fileIO.open("../Assignment-02-Code Files/Data.CS.SFSU.txt");

    if(fileIO.fail())
    {
        cout << "File not found." << endl;
        exit(0);
    }

    cout << "Loading Data..." << endl;
    while(getline(fileIO, line))
    {
        cout << line << endl;
        //getInfo(fileIO, line);
    }
    cout << "Loading Completed..." << endl;

    cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
    fileIO.close();
}