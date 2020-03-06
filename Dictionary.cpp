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
        database.insert(make_pair(dictionaryWordData.at(i).word, dictionaryWordData.at(i).definition));
        //cout << adverb.at("placeholder") << endl;
    }
    /*for(auto& elm: adjective)
    {
        cout << elm.first << "[adjective]:" << elm.second << endl;
    }*/
    //cout << adjective.find("placeholder") << endl;
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
    if(counter == 1)
    {
        oneArg(word);
    }
    if(counter == 2 && stringVector[1] == "distinct")
    {
        twoArg(word,"distinct");
    }
    else if(counter == 2)
    {
        twoArg(word,stringVector[1]);
    }
    if(counter == 3 && stringVector[2] == "distinct")
    {
        threeArg(word,pos, true);
    }
    if(stringVector[1] != "oops")
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
    /*typedef multimap<string, string>::iterator MMAPIterator;
    pair<MMAPIterator, MMAPIterator> result = adjective.equal_range(word);

    for(MMAPIterator it = result.first; it!=result.second; it++)
    {
        cout << it->first << "[POS]" << it->second << endl;
    }*/
    cout << "|\n";
    for(auto& elm: adjective) { if(elm.first == word) { cout << elm.first << "[adjective]:" << elm.second << endl; } }
    for(auto& elm: adverb) { if(elm.first == word) { cout << elm.first << "[adverb]:" << elm.second << endl; } }
    for(auto& elm: conjunction) { if(elm.first == word) { cout << elm.first << "[conjunction]:" << elm.second << endl; } }
    for(auto& elm: interjection) { if(elm.first == word) { cout << elm.first << "[interjection]:" << elm.second << endl; } }
    for(auto& elm: noun) { if(elm.first == word) { cout << elm.first << "[noun]:" << elm.second << endl; } }
    for(auto& elm: preposition) { if(elm.first == word) { cout << elm.first << "[preposition]:" << elm.second << endl; } }
    for(auto& elm: pronoun) { if(elm.first == word) { cout << elm.first << "[pronoun]:" << elm.second << endl; } }
    for(auto& elm: verb) { if(elm.first == word) { cout << elm.first << "[verb]:" << elm.second << endl; } }
    cout << "|\n";
}

void Dictionary::twoArg(const string& word, const string& pos)
{
    if(pos == "distinct")
    {
        for(auto it = adjective.begin(),end = adjective.end(); it!=end; it = adjective.upper_bound(it->first))
        {
            if(adjective.begin()->first == word) { cout << it->first << "[adjective]" << it->second << endl; }
            //cout << adjective.begin()->first << endl;
        }
    }
    else if(!(pos == "distinct"))
    {
        for(auto& elm: adjective) { if(elm.first == word && adjective.count(elm.first) == 2) { cout << elm.first << "[adjective]:" << elm.second << endl; } }
        for(auto& elm: adverb) { if(elm.first == word && pos == "adverb") { cout << elm.first << "[adverb]:" << elm.second << endl; } }
        for(auto& elm: conjunction) { if(elm.first == word && pos == "conjunction") { cout << elm.first << "[conjunction]:" << elm.second << endl; } }
        for(auto& elm: interjection) { if(elm.first == word && pos == "interjection") { cout << elm.first << "[interjection]:" << elm.second << endl; } }
        for(auto& elm: noun) { if(elm.first == word && pos == "noun") { cout << elm.first << "[noun]:" << elm.second << endl; } }
        for(auto& elm: preposition) { if(elm.first == word && pos == "preposition") { cout << elm.first << "[preposition]:" << elm.second << endl; } }
        for(auto& elm: pronoun) { if(elm.first == word && pos == "pronoun") { cout << elm.first << "[pronoun]:" << elm.second << endl; } }
        for(auto& elm: verb) { if(elm.first == word && pos == "verb") { cout << elm.first << "[verb]:" << elm.second << endl; } }

    }
}

void Dictionary::threeArg(const string& word, const string& pos, bool distinct)
{

}
