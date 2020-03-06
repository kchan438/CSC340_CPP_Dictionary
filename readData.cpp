//
// Created by Kevin Chan on 3/2/20.
//

#include "readData.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

readData::readData() = default; //constructor

vector<wordInfo> readData::readFile()
{

    ifstream fileIO;
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
    while(!fileIO.eof())
    {
        //readToken(line);
        getInfo(fileIO, wordData);
    }
    cout << "Loading Completed..." << endl;

    cout << "! Closing data file... ./Data.CS.SFSU.txt" << endl;
    fileIO.close();
    return wordData;
}

void readData::getInfo(ifstream& file, vector<wordInfo>& wordData)
{
    string wordLine;
    string word;
    string pos;
    string definition;

    getline(file, wordLine);
    stringstream string = stringstream(wordLine);   //puts the line we grabbed, into a stringstream so we can traverse through it
    getline(string, word, '|');   //gets search word ending before '|' char
    //gets POS word ending before ' ' char
    //while there is a POS next after every definition.
    while(getline(string,pos, ' ')) //this while loop will get a new POS and definition from each word until the last char is '\r'
    {
        string.ignore(5,' ');   //skips the arrow in the beginning
        getline(string,definition, '|'); //gets the definition of the POS
        if(definition.back()=='\r')
        {
            definition.pop_back();  //because we don't want the return carriage processed
        }
        readData::wordData.push_back(wordInfo{word, pos, definition});  //then push the struct into the vector wordInfo for processing later
    }
    //cout << "word: " << word << " [" << pos << "]: " << definition << endl;
}

void printString(const wordInfo& wordData)
{
    cout << wordData.word << " [" << wordData.pos << "]: " << wordData.definition << endl;
}