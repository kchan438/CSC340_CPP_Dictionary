#include <iostream>
#include "Dictionary.hpp"

int main(int argc, const char * argv[]) {
    Dictionary d = Dictionary();
    d.init();
    d.getInputFromConsole();

    return 0;
}
