
#ifndef CSC340_CPP_DICTIONARY_READDATA_H
#define CSC340_CPP_DICTIONARY_READDATA_H

#include <string>
using namespace std;
class readData
{
public:
    readData();
    void readFile();
    static void readToken(const string& line);
};
#endif //CSC340_CPP_DICTIONARY_READDATA_H
