
#ifndef CSC340_CPP_DICTIONARY_READDATA_H
#define CSC340_CPP_DICTIONARY_READDATA_H

#include <string>
#include <vector>
using namespace std;

struct wordInfo
{
    string word;
    string pos;
    string definition;
};

class readData
{
public:
    readData();
    vector<struct wordInfo> readFile();
    static void readToken(const string& line);
    void getInfo(ifstream& file, vector<wordInfo>& wordData);
    vector<wordInfo> wordData;
};
#endif //CSC340_CPP_DICTIONARY_READDATA_H
