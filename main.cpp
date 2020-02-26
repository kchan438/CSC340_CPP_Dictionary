#include <iostream>
#include <fstream>

using namespace std;

int main() {

    //Part A: Our program must produce identical output: ASMT02_PA_Run1.txt
    //and ASMT02_PA_Run2.txt
    //do a file IO stream to read both of the entire files

    cout << "Part A: Reading 2 Files" << endl;

    ofstream fileIO;

    fileIO.open("/Assignment-02-Code/ASMT02_PA_Run1.txt");
    fileIO.open("/Assignment-02-Code/ASMT02_PA_Run2.txt");

    

    return 0;
}
