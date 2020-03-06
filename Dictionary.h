//
// Created by Kevin Chan on 3/2/20.
//

#ifndef CSC340_CPP_DICTIONARY_DICTIONARY_H
#define CSC340_CPP_DICTIONARY_DICTIONARY_H
#include "readData.h"
#include <map>

class Dictionary
{
public:
    Dictionary();
    void initialize();
    void search(const string& phrase);
private:
    //map<string,string> adjective;
    multimap<string,string> adjective;
    map<string,string> adverb;
    map<string,string> conjunction;
    map<string,string> interjection;
    map<string,string> noun;
    map<string,string> preposition;
    map<string,string> pronoun;
    map<string,string> verb;
};

#endif //CSC340_CPP_DICTIONARY_DICTIONARY_H
