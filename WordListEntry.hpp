#ifndef WordList_hpp
#define WordList_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

struct WordListEntry{
    std::string word;
    std::string definition;
    std::string speechType;
};

namespace WordList{
    std::vector<WordListEntry> makeWordList();
    void getWord(std::ifstream& inFile,std::vector<WordListEntry>& v);
    std::string toString(const WordListEntry& e);
    std::string capitalize(std::string s);
    bool compareSpeechType(const WordListEntry& w1, const WordListEntry& w2);
}

#endif /* WordList_hpp */
