//
// Created by Kevin Chan on 3/2/20.
//
#include "Dictionary.h"
#include "readData.h"
#include <map>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>
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
    vector<wordInfo> dictionaryWordData = readobj.readFile();
    //this for loop should initialize each multimap with the duplicate POS definitio
    for(int i = 0; i < dictionaryWordData.size(); i++)
    {
        if(dictionaryWordData.at(i).pos == "adjective")
        {
            //adjective[dictionaryWordData.at(i).word] = dictionaryWordData.at(i).definition;
            adjective.insert(make_pair(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition));
        }
        else if(dictionaryWordData.at(i).pos == "adverb")
        {
            adverb.insert(make_pair(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition));
        }
        else if(dictionaryWordData.at(i).pos == "conjunction")
        {
            conjunction.insert(make_pair(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition));
        }
        else if(dictionaryWordData.at(i).pos == "interjection")
        {
            interjection.insert(make_pair(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition));
        }
        else if(dictionaryWordData.at(i).pos == "noun")
        {
            noun.insert(make_pair(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition));
        }
        else if(dictionaryWordData.at(i).pos == "preposition")
        {
            preposition.insert(make_pair(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition));
        }
        else if(dictionaryWordData.at(i).pos == "pronoun")
        {
            pronoun.insert(make_pair(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition));
        }
        else if(dictionaryWordData.at(i).pos == "verb")
        {
            verb.insert(make_pair(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition));
        }

        //cout << adverb.at("placeholder") << endl;
    }
    /*for(auto& elm: adjective)
    {
        cout << elm.first << "[adjective]:" << elm.second << endl;
    }*/
}

void Dictionary::search(const string& phrase)
{
    // Used to split string around spaces.
    stringstream ss(phrase);
    //Loads only 3 phrases max
    vector<string> stringVector(3);
    int counter = 0;
    string word;
    string pos;

    while(getline(ss,stringVector[counter], ' '))
    {
        counter++;
    }
    cout << "word: " << stringVector[0] << endl;
    cout << "counter :" << counter << endl;

    //word = stringVector[0];
    //cout << "word " << word;

    if(counter == 0 || counter > 3)
    {
        cout << "Must be between 1 and 3 words" << endl;
    }
    if(stringVector[0] == "!q" || stringVector[0] == "!Q" )
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
        //oneArg(word);
    }
}

void Dictionary::oneArg(const string& word)
{
    typedef multimap<string, string>::iterator MMAPIterator;
    pair<MMAPIterator, MMAPIterator> result = adjective.equal_range(word);

    for(MMAPIterator it = result.first; it!=result.second; it++)
    {
        cout << it->first << "[POS]" << it->second << endl;
    }
}

void Dictionary::print(const std::vector<std::string>& messages){
    std::cout << "       |" << std::endl;
    for(auto i=messages.begin();i!=messages.end();i++){
        std::cout << *i << std::endl;
    }
    std::cout << "       |" << std::endl;
}
