//
// Created by Kevin Chan on 3/2/20.
//

#ifndef CSC340_CPP_DICTIONARY_DICTIONARY_H
#define CSC340_CPP_DICTIONARY_DICTIONARY_H
#include "readData.h"
#include <map>
#include <unordered_set>

class Dictionary
{
public:
    Dictionary();
    void initialize();
    void search(const string& phrase);
    void oneArg(const string& word);
    void twoArg(const string& word, const string& pos);
    void threeArg(const string& word, const string& pos);
private:
    unordered_set<string> posList;

    multimap<string, wordInfo> dictionary;
    multimap<string, wordInfo> adjective1;
    multimap<string, wordInfo> adverb1;
    multimap<string, wordInfo> conjunction1;
    multimap<string, wordInfo> interjection1;
    multimap<string, wordInfo> noun1;
    multimap<string, wordInfo> preposition1;
    multimap<string, wordInfo> pronoun1;
    multimap<string, wordInfo> verb1;
};

#endif //CSC340_CPP_DICTIONARY_DICTIONARY_H
