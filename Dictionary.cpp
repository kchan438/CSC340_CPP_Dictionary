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
    posList.insert("adjective");
    posList.insert("adverb");
    posList.insert("conjunction");
    posList.insert("interjection");
    posList.insert("noun");
    posList.insert("preposition");
    posList.insert("pronoun");
    posList.insert("verb");
}

//this is where we will create dictionary multimaps and store data here
void Dictionary::initialize()
{
    //will have separate maps organized by POS.
    //<word,definition>
    //will need to find a way to pass over and read data to store each word in each map
    readData readobj;
    vector<wordInfo> dictionaryWordData = readobj.readFile();
    //this for loop should initialize each multimap with the duplicate POS definition

    for(auto iterator = dictionaryWordData.begin(); iterator!=dictionaryWordData.end(); iterator++)
    {
        pair<string,wordInfo> data = make_pair(iterator->word, *iterator);
        dictionary.insert(data);
        if(iterator->pos == "adjective") { adjective1.insert(data); }
        if(iterator->pos == "adverb") { adverb1.insert(data); }
        if(iterator->pos == "conjunction") { conjunction1.insert(data); }
        if(iterator->pos == "interjection") { interjection1.insert(data); }
        if(iterator->pos == "noun") { noun1.insert(data); }
        if(iterator->pos == "preposition") { preposition1.insert(data); }
        if(iterator->pos == "pronoun") { pronoun1.insert(data); }
        if(iterator->pos == "verb") { verb1.insert(data); }
    }
}

void Dictionary::search(const string& phrase)
{
    // Used to split string around spaces.
    stringstream ss(phrase);
    vector<string> stringVector;
    int counter = 0;
    string word;
    string pos;

    while(getline(ss,word, ' '))
    {
        stringVector.push_back(word);
        counter++;
    }

    if(counter == 0 || counter > 3)
    {
        cout << "Must be between 1 and 3 words" << endl;
    }
    else if(stringVector[0] == "!q" || stringVector[0] == "!Q" )
    {
        cout << "-----THANK YOU-----" << endl;
        exit(0);
    }
    else if(counter == 1)
    {
        oneArg(stringVector[0]);
    }
    else if(counter == 2 && stringVector[1] == "distinct")
    {
        twoArg(stringVector[0],"distinct");
    }
    else if(counter == 2)
    {
        twoArg(stringVector[0],stringVector[1]);
    }
    else if(counter == 3 && stringVector[2] == "distinct")
    {
        threeArg(stringVector[0],stringVector[1]);
    }
    else if(stringVector[1] == "oops")
    {
        cout << "2nd argument must be a part of speech or \"distinct\"" << endl;
    }
}

void Dictionary::oneArg(const string& word)
{
    for(auto& elm: adjective1) { if(elm.first == word) { cout << elm.first << "[adjective]:" << elm.second.definition << endl; } }
    for(auto& elm: adverb1) { if(elm.first == word) { cout << elm.first << "[adverb]:" << elm.second.definition << endl; } }
    for(auto& elm: conjunction1) { if(elm.first == word) { cout << elm.first << "[conjunction]:" << elm.second.definition << endl; } }
    for(auto& elm: interjection1) { if(elm.first == word) { cout << elm.first << "[interjection]:" << elm.second.definition << endl; } }
    for(auto& elm: noun1) { if(elm.first == word) { cout << elm.first << "[noun]:" << elm.second.definition << endl; } }
    for(auto& elm: preposition1) { if(elm.first == word) { cout << elm.first << "[preposition]:" << elm.second.definition << endl; } }
    for(auto& elm: pronoun1) { if(elm.first == word) { cout << elm.first << "[pronoun]:" << elm.second.definition << endl; } }
    for(auto& elm: verb1) { if(elm.first == word) { cout << elm.first << "[verb]:" << elm.second.definition << endl; } }
}

void Dictionary::twoArg(const string& word, const string& pos)
{
    if(pos == "distinct")
    {
        for(auto it = adjective1.begin(),end = adjective1.end(); it!=end; it = adjective1.upper_bound(it->first))
        {
            if(it->first == word && it->second.pos == "adjective")
            {
                cout << it->first << "[" << it->second.pos << "]" << it->second.definition << endl;
            }
        }
        for(auto it = adverb1.begin(),end = adverb1.end(); it!=end; it = adverb1.upper_bound(it->first))
        {
            if(it->first == word && it->second.pos == "adverb")
            {
                cout << it->first << "[" << it->second.pos << "]" << it->second.definition << endl;
            }
        }
        for(auto it = conjunction1.begin(),end = conjunction1.end(); it!=end; it = conjunction1.upper_bound(it->first))
        {
            if(it->first == word && it->second.pos == "conjunction")
            {
                cout << it->first << "[" << it->second.pos << "]" << it->second.definition << endl;
            }
        }
        for(auto it = interjection1.begin(),end = interjection1.end(); it!=end; it = interjection1.upper_bound(it->first))
        {
            if(it->first == word && it->second.pos == "interjection")
            {
                cout << it->first << "[" << it->second.pos << "]" << it->second.definition << endl;
            }
        }
        for(auto it = noun1.begin(),end = noun1.end(); it!=end; it = noun1.upper_bound(it->first))
        {
            if(it->first == word && it->second.pos == "noun")
            {
                cout << it->first << "[" << it->second.pos << "]" << it->second.definition << endl;
            }
        }
        for(auto it = preposition1.begin(),end = preposition1.end(); it!=end; it = preposition1.upper_bound(it->first))
        {
            if(it->first == word && it->second.pos == "preposition")
            {
                cout << it->first << "[" << it->second.pos << "]" << it->second.definition << endl;
            }
        }
        for(auto it = pronoun1.begin(),end = pronoun1.end(); it!=end; it = pronoun1.upper_bound(it->first))
        {
            if(it->first == word && it->second.pos == "pronoun")
            {
                cout << it->first << "[" << it->second.pos << "]" << it->second.definition << endl;
            }
        }
    }
    else if(!(pos == "distinct"))
    {
        for(auto& elm: adjective1) { if(elm.first == word && adjective1.count(elm.first) >= 2) { cout << elm.first << "[adjective]:" << elm.second.definition << endl; } }
        for(auto& elm: adverb1) { if(elm.first == word && adverb1.count(elm.first) >= 2) { cout << elm.first << "[adverb]:" << elm.second.definition << endl; } }
        for(auto& elm: conjunction1) { if(elm.first == word && conjunction1.count(elm.first) >= 2) { cout << elm.first << "[conjunction]:" << elm.second.definition << endl; } }
        for(auto& elm: interjection1) { if(elm.first == word && interjection1.count(elm.first) >= 2) { cout << elm.first << "[interjection]:" << elm.second.definition << endl; } }
        for(auto& elm: noun1) { if(elm.first == word && noun1.count(elm.first) >= 2) { cout << elm.first << "[noun]:" << elm.second.definition << endl; } }
        for(auto& elm: preposition1) { if(elm.first == word && preposition1.count(elm.first) >= 2) { cout << elm.first << "[preposition]:" << elm.second.definition << endl; } }
        for(auto& elm: pronoun1) { if(elm.first == word && pronoun1.count(elm.first) >= 2) { cout << elm.first << "[pronoun]:" << elm.second.definition << endl; } }
        for(auto& elm: verb1) { if(elm.first == word && verb1.count(elm.first) >= 2) { cout << elm.first << "[verb]:" << elm.second.definition << endl; } }
    }
}

void Dictionary::threeArg(const string& word, const string& pos)
{
    for(auto it = dictionary.begin(),end = dictionary.end(); it!=end; it = dictionary.upper_bound(it->first))
    {
        if(it->first == word /*&& it->second.pos == pos*/)
        {
            cout << it->first << "[" << it->second.pos << "]" << it->second.definition << endl;
        }
    }
}
