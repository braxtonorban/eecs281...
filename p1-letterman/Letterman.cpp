// Identifier: 50EB44D3F029ED934858FFFCEAC3547C68768FC9
#include <string>
#include <vector>
#include <iostream>
#include <getopt.h>
#include <deque>
#include "Letterman.hpp"

using namespace std;

Letterman::Letterman() {
    dictContainsStart = false;
    dictContainsTarget = false;
    isStack = false;
    start = "";
    startIndex = 0;
    target = "";
    isWordFormat = false;
    isChange = false;
    isDelete = false;
    isInsert = false;
    isSwap = false;
}

void Letterman::setIsStack(bool stackBool) {
    isStack = stackBool;
}

void Letterman::setStart(string startString) {
    start = startString;
}

void Letterman::setTarget(string targetString) {
    target = targetString;
}

void Letterman::setOutput(bool outputBool) {
    isWordFormat = outputBool;
}

void Letterman::setChange(bool changeBool) {
    isChange = changeBool;
}

void Letterman::setLength(bool lengthBool) {
    isDelete = lengthBool;
    isInsert = lengthBool;
}

void Letterman::setSwap(bool swapBool) {
    isSwap = swapBool;
}

void Letterman::readDict() {
    // use first line to determine dictionary type
    string dictType;
    cin >> dictType;

    // use the second line to determine the number of entries
    string numEntriesString;
    cin >> numEntriesString;

    string newEntry = "";
    getline(cin, newEntry);
    newEntry = "";

    // split into simple and complex
    if (dictType == "S") {
        while (getline(cin, newEntry)) {
            if ((newEntry[0] == '/') && (newEntry[1] == '/')) {
                newEntry = "";
            }
            else if (newEntry == start) {
                startIndex = entries.size();
                dictContainsStart = true;
                Entry newestEntry(newEntry);
                entries.push_back(newestEntry);
                newEntry = "";
            }
            else if (newEntry == target) {
                dictContainsTarget = true;
                Entry newestEntry(newEntry);
                entries.push_back(newestEntry);
                newEntry = "";
            }
            else {
                Entry newestEntry(newEntry);
                entries.push_back(newestEntry);
                newEntry = "";
            }
        }
    } // if (simple dict)
    else {} // else (complex dict)
} // readDict

void Letterman::search() {   
    // adding start to sc
    sc.push_back(startIndex);
    entries[startIndex].discovered();
    backtrace.push(startIndex);

    string currWord = "";

    while (entries[backtrace.front()].getWord() != target) {
        // fetch and remove
        if (sc.empty()) {
            break;
        }

        if (isStack) {
            currWord = entries[sc.back()].getWord();
            sc.pop_back();
        }
        else {
            currWord = entries[sc.front()].getWord();
            sc.pop_front();
        }

        // investigation
        if (isChange) {
            for (size_t dictIndex = 0; dictIndex < entries.size(); ++dictIndex) {
                if (!(entries[dictIndex].isDisc())) {
                    if (entries[dictIndex].getWord().length() == currWord.length()) {
                        if (changeSimilar(currWord, entries[dictIndex].getWord())) {
                            entries[dictIndex].discovered();
                            sc.push_back(dictIndex);
                            backtrace.push(dictIndex);
                        }
                    }
                }
            }
        }
    }
}

bool Letterman::changeSimilar(string currWord, string invWord) {
    int numDiffLetters = 0;

    for (size_t i = 0; i < currWord.length(); ++i) {
        if (currWord[i] != invWord[i]) {
            ++numDiffLetters;
        }
    }

    return numDiffLetters == 1;
}

void Letterman::output() {
    if (isWordFormat) {
        cout << "Words in morph: " << backtrace.size() << "\n";

        while (!backtrace.empty()) {
            cout << entries[backtrace.front()].getWord() << "\n";
            backtrace.pop();
        }
    }
}