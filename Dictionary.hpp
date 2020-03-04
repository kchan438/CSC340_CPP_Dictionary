

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include "WordListEntry.hpp"

class Dictionary{
    typedef std::unordered_multimap<std::string,WordListEntry> wordMap;
private:
    wordMap dict;
    std::unordered_set<std::string> partsOfSpeech;
    const std::string ERROR_ONE = "<Not found>";
    const std::string ERROR_TWO = "<Second argument must be a part of speech or \"distinct\">";

public:
    Dictionary();
    void init();
    bool isPartOfSpeech(const std::string& s);
    std::vector<std::string> querryDictionary(const std::string& word, const std::string& speechType, bool distinct);
    void getInputFromConsole();
    void print(const std::vector<std::string>& messages);
    std::vector<std::string> parse(const std::string& input);
    static std::string toLower(std::string s);
};

#endif /* Dictionary_hpp */
