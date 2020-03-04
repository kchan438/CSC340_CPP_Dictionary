#include "WordListEntry.hpp"

std::vector<WordListEntry> WordList::makeWordList(){
    std::vector<WordListEntry> v;
//    std::cout << "! Opening data file... ./Data.CS.SFSU.txt" << std::endl;
    std::ifstream inStream = std::ifstream("Resources/Data.CS.SFSU.txt");
//    std::cout << "! Loading data..." << std::endl;
    while(!inStream.eof()){
        WordList::getWord(inStream,v);
    }
//    std::cout << "! Loading completed..." << std::endl;
//    std::cout << "! Closing data file... ./Data.CS.SFSU.txt" << std::endl << std::endl;
    inStream.close();
    return v;
}

void WordList::getWord(std::ifstream& inFile, std::vector<WordListEntry>& v){
    std::string input;
    std::string word;
    std::string partSpeech;
    std::string def;
    getline(inFile,input);
    std::stringstream lineStream = std::stringstream(input);
    getline(lineStream,word,'|');
    while(getline(lineStream,partSpeech,' ')){
        lineStream.ignore(5,' ');
        getline(lineStream,def,'|');
        if(def.back()=='\r') def.pop_back();
        v.push_back(WordListEntry{word,def,partSpeech});
    }
}

std::string WordList::capitalize(std::string s){
    std::regex courseTitle("([cC][sS][cC])(\\d+)");
    s = std::regex_replace(s,courseTitle,"CSC$2");
    s.front() = std::toupper(s.front());
    return s;
}

std::string WordList::toString(const WordListEntry &e){
    return "       " + WordList::capitalize(e.word) + " [" + e.speechType + "] : " + e.definition;
}

bool WordList::compareSpeechType(const WordListEntry &w1, const WordListEntry &w2){
    if(w1.speechType == w2.speechType){
        return w1.definition < w2.definition;
    }
    return w1.speechType < w2.speechType;
}

