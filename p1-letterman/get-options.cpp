// Identifier: 50EB44D3F029ED934858FFFCEAC3547C68768FC9
#include <string>
#include <getopt.h>
#include "Letterman.hpp"

using namespace std;

void Letterman::getOptions(int argc, char** argv) {
    int option_index = 0, option = 0;

    opterr = false;

    struct option longOpts[] = {{ "help", no_argument, nullptr, 'h' },
                                { "queue", no_argument, nullptr, 'q' },
                                { "stack", no_argument, nullptr, 's' },
                                { "begin", required_argument, nullptr, 'b' },
                                { "end", required_argument, nullptr, 'e'},
                                { "output", required_argument, nullptr, 'o'}, 
                                { "change", no_argument, nullptr, 'c'}, 
                                { "length", no_argument, nullptr, 'l'},
                                { "swap", no_argument, nullptr, 'p'},
                                { nullptr, 0, nullptr, '\0'}};

    char output = '\0';
    int numRoutingScheme = 0;
    int numModModes = 0;
    int numBegWords = 0;
    int numEndWords = 0;

    while ((option = getopt_long(argc, argv, "hqsb:e:o:clp", longOpts, &option_index)) != -1) {
        switch (option) {
            case 'h':
                cout << "help me\n";
                exit(0);
            
            case 'q':
                setIsStack(false);
                ++numRoutingScheme;
                break;
            
            case 's':
                setIsStack(true);
                ++numRoutingScheme;
                break;
            
            case 'b':
                setStart(optarg);
                ++numBegWords;
                break;

            case 'e':
                setTarget(optarg);
                ++numEndWords;
                break;
            
            case 'o':
                output = *optarg;
                if (output == 'M') {
                    setOutput(false);
                }
                else if (output == 'W') {
                    setOutput(true);
                }
                else if (output == '\0') {
                    setOutput(true);
                }
                else {
                    cerr << "Invalid output mode specified\n";
                    exit(1);
                }
                break;

            case 'c':
                setChange(true);
                ++numModModes;
                break;

            case 'l':
                setLength(true);
                ++numModModes;
                break;

            case 'p':
                setSwap(true);
                ++numModModes;
                break;
        } 
    }

    if (numRoutingScheme > 1) {
        cerr << "Conflicting or duplicate stack and queue specified\n";
        exit(1);
    }
    else if (numRoutingScheme < 1) {
        cerr << "Must specify one of stack or queue\n";
        exit(1);
    }
    else {}

    if (numModModes == 0) {
        cerr << "Must specify at least one modification mode (change length swap)\n";
        exit(1);
    }

    if (numBegWords == 0) {
        cerr << "Beginning word not specified\n";
        exit(1);
    }

    if (numEndWords == 0) {
        cerr << "Ending word not specified\n";
        exit(1);
    }

    if (!isDelete) {
        if (start.length() != target.length()) {
            cerr << "The first and last words must have the same length when length mode is off\n";
            exit(1);
        }
    }
}