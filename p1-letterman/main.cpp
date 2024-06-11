// Identifier: 50EB44D3F029ED934858FFFCEAC3547C68768FC9
#include <string>
#include <vector>
#include <iostream>
#include <getopt.h>
#include <deque>
#include "Letterman.hpp"

using namespace std;

int main(int argc, char** argv) {
    Letterman myLetterman;
    myLetterman.getOptions(argc, argv);
    myLetterman.readDict();
    if (!myLetterman.dictContainsStart) {
        cerr << "Beginning word does not exist in the dictionary\n";
        exit(1);
    }
    if (!myLetterman.dictContainsTarget) {
        cerr << "Ending word does not exist in the dictionary\n";
        exit(1);
    }

    myLetterman.search();
    myLetterman.output();

    return 0;    
}

// 1 sync with standard io false
// 2 declare a Letterman object
// 3 have the letterman object process the command line
// 4 have the letterman object read the dictionary
// 5 have the letterman object do the searching
// 6 have the letterman object do the output
// 7 return 0

// sc contains all words that are similar under the given modes
// sc is made of ints, and it has the indices of words marked as similar