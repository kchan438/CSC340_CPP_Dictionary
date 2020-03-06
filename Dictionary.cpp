//
// Created by Kevin Chan on 3/2/20.
//
#include "Dictionary.h"
#include "readData.h"
#include <map>
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
    vector<string> stringVector;
    int counter = 0;
    string word;
    string pos;

    /*istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> stringVector(begin,end);
    copy(stringVector.begin(),stringVector.end(),ostream_iterator<std::string>(std::cout, "\n"));*/

    while(getline(ss,word, ' '))
    {
        stringVector.push_back(word);
        counter++;
    }

    //word = stringVector[0];
    //cout << "word " << word;

    if(counter == 0 || counter > 3)
    {
        cout << "Must be between 1 and 3 words" << endl;
    }
    if(counter == 1)
    {
        oneArg(word);
    }
    if(counter == 2 && stringVector[1] == "distinct")
    {
        twoArg(word,"distinct");
    }
    if(counter == 3 && stringVector[2] == "distinct")
    {
        threeArg(word,pos, "distinct");
    }
    if(stringVector[1] == "oops")
    {
        cout << "2nd argument must be a part of speech or \"distinct\"" << endl;
    }
    if(stringVector[0] == "!q" || stringVector[0] == "!Q" )
    {
        cout << "-----THANK YOU-----" << endl;
        exit(0);
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

void Dictionary::twoArg(const string& word, const string& pos)
{

}

void Dictionary::threeArg(const string& word, const string& pos, const string& distinct)
{

}