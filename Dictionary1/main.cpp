#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Hello, World!" << std::endl;

    ifstream inText;

    //get the name of the input file from the user
    string inputFileName;
    cout << "Enter the input file name " << "\n";
    cin >> inputFileName;

    //Now we can open the input file and verify it opened ok
    //Our file name is a 'string'
    //however our function needs an argument of type 'c_string'.
    //Thus 'c_str()' method is very useful for when we need a c String

    inText.open(inputFileName.c_str());
    if (inText.is_open()){
        cout << "File " << inputFileName << " opened OK." << "\n";
    }
    else{
        cout <<"Error : " << inputFileName << "Is unable to open";
        exit(0);

    }

    inText.close();



















    return 0;
}
