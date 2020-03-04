#include "Dictionary.hpp"

Dictionary::Dictionary(){
    std::unordered_multimap<std::string, WordListEntry> dict;
    partsOfSpeech = std::unordered_set<std::string>();
    partsOfSpeech.insert("noun");
    partsOfSpeech.insert("adjective");
    partsOfSpeech.insert("verb");
    partsOfSpeech.insert("adverb");
    partsOfSpeech.insert("conjunction");
    partsOfSpeech.insert("interjection");
    partsOfSpeech.insert("preposition");
    partsOfSpeech.insert("pronoun");
}

void Dictionary::init(){
    std::vector<WordListEntry> v = WordList::makeWordList();
    for(auto iter = v.begin(); iter!= v.end(); iter++){
        std::pair<std::string,WordListEntry> p = std::make_pair(Dictionary::toLower(iter->word),*iter);
        dict.insert(p);
    }
}

bool Dictionary::isPartOfSpeech(const std::string& s){
    if(s==""){
        return true;
    } else{
        return partsOfSpeech.find(s) != partsOfSpeech.end();
    }
}

std::string Dictionary::toLower(std::string s){
    for(std::string::iterator i = s.begin();i!=s.end();i++){
        *i = std::tolower(*i);
    }
    return s;
}

std::vector<std::string> Dictionary::querryDictionary(const std::string& word, const std::string& speechType, bool distinct){
    std::vector<std::string> v;
    std::vector<WordListEntry> w;
    std::string wordCase = Dictionary::toLower(word);
    std::string speechTypeCase = Dictionary::toLower(speechType);
    if(dict.find(wordCase)==dict.end()){
        v.push_back(ERROR_ONE);
        return v;
    }
    if(!isPartOfSpeech(speechType)){
        v.push_back(ERROR_TWO);
        return v;
    }
    auto range = dict.equal_range(wordCase);
    if(speechType != ""){
        for(auto i=range.first;i!=range.second;i++){
            if(i->second.speechType == speechTypeCase){
                w.push_back(i->second);
                std::sort(w.begin(),w.end(),WordList::compareSpeechType);
            }
        }
        if(w.empty()){
            v.push_back(ERROR_ONE);
            return v;
        }
    } else{
        for(auto i=range.first;i!=range.second;i++){
            w.push_back(i->second);
            std::sort(w.begin(),w.end(),WordList::compareSpeechType);
        }
    }
    for(auto i=w.begin();i!=w.end();i++){
        v.push_back(WordList::toString(*i));
    }
    if(distinct){
        std::unordered_set<std::string> alreadyPrinted;
        std::vector<std::string> vCopy;
        for(auto i=v.begin();i!=v.end();i++){
            if(alreadyPrinted.find(*i)==alreadyPrinted.end()){
                alreadyPrinted.insert(*i);
                vCopy.push_back(*i);
            }
        }
        v=vCopy;
    }
    return v;
}

void Dictionary::getInputFromConsole(){
    std::cout << "----- DICTIONARY 340 C++ -----" << std::endl;
    while(true){
        std::cout << "Search: ";
        std::string s;
        getline(std::cin, s);
        print(parse(s));
    }
}

std::vector<std::string> Dictionary::parse(const std::string &input){
    std::vector<std::string> inputs(3);
    std::stringstream inStream = std::stringstream(input);
    int i=0;
    while(getline(inStream,inputs[i],' ')){
        i++;
    }
    if(i < 1 || i > 3){
        std::cout << "Input must be between 1 and 3 words" << std::endl;
        return std::vector<std::string>();
    }
    if(Dictionary::toLower(inputs[0])=="!q"){
        std::cout << "-----THANK YOU-----" << std::endl;
        exit(0);
    }
    if(i==1){
        return querryDictionary(inputs[0], "", false);
    }
    if(i==2){
        if(Dictionary::toLower(inputs[1])=="distinct"){
            return querryDictionary(inputs[0], "", true);
        }
        return querryDictionary(inputs[0], inputs[1], false);
    }
    return querryDictionary(inputs[0], inputs[1], Dictionary::toLower(inputs[2])=="distinct");
}

void Dictionary::print(const std::vector<std::string>& messages){
    std::cout << "       |" << std::endl;
    for(auto i=messages.begin();i!=messages.end();i++){
        std::cout << *i << std::endl;
    }
    std::cout << "       |" << std::endl;
}


