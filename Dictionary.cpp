//
// Created by Kevin Chan on 3/2/20.
//
#include "Dictionary.h"
#include "readData.h"
#include <map>
#include <unordered_map>
#include <sstream>
#include <iostream>
using namespace std;
Dictionary::Dictionary()
{
    /*map<string,string> adjective;
    map<string,string> adverb;
    map<string,string> conjunction;
    map<string,string> interjection;
    map<string,string> noun;
    map<string,string> preposition;
    map<string,string> pronoun;
    map<string,string> verb;*/
}

//this is where we will create dictionary hashmaps and store data here
void Dictionary::initialize()
{
    //will have separate maps organized by POS.
    //<word,definition>
    //will need to find a way to pass over and read data to store each word in each map
    readData readobj;
    vector<wordInfo> dictionaryWordData = readobj.wordData;
    adjective.insert
    for(int i = 0; i < dictionaryWordData.size()-1; i++)
    {
        if(dictionaryWordData.at(i).pos == "adjective")
        {
            adjective.insert(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition);
        }
        else if(dictionaryWordData.at(i).pos == "adverb")
        {
            adverb.insert(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition);
        }
        else if(dictionaryWordData.at(i).pos == "conjunction")
        {
            conjunction.insert(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition);
        }
        else if(dictionaryWordData.at(i).pos == "interjection")
        {
            interjection.insert(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition);
        }
        else if(dictionaryWordData.at(i).pos == "noun")
        {
            noun.insert(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition);
        }
        else if(dictionaryWordData.at(i).pos == "pronoun")
        {
            pronoun.insert(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition);
        }
        else if(dictionaryWordData.at(i).pos == "verb")
        {
            verb.insert(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition);
        }

        cout << adverb.at("placeholder") << endl;
    }

}

void search(const string& phrase)
{
    // Used to split string around spaces.
    stringstream ss(phrase);
    vector<string> stringVector;
    int counter = 0;
    string word;
    string pos;

    while(getline(ss,stringVector[counter], ' '))
    {
        counter++;
    }
    if(counter == 0 || counter > 3)
    {
        cout << "Must be between 1 and 3 words" << endl;
    }
    if(stringVector[0] == "!q")
    {
        cout << "-----THANK YOU-----" << endl;
        exit(0);
    }
    if(stringVector[1] == "oops")
    {
        cout << "2nd argument must be a part of speech or \"distinct\"" << endl;
    }
    if(counter == 1)
    {

    }
}