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
    void getInputFromConsole();
    void search(const string& phrase);
    void oneArg(const string& word);

private:


    //map<string,string> adjective;
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
