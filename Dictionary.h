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
    void oneArg(const string& word);
    void twoArg(const string& word, const string& pos);
    void threeArg(const string& word, const string& pos, const string& distinct);
private:
    multimap<string,string> adjective;
    multimap<string,string> adverb;
    multimap<string,string> conjunction;
    multimap<string,string> interjection;
    multimap<string,string> noun;
    multimap<string,string> preposition;
    multimap<string,string> pronoun;
    multimap<string,string> verb;
};

#endif //CSC340_CPP_DICTIONARY_DICTIONARY_H
