// Identifier: 50EB44D3F029ED934858FFFCEAC3547C68768FC9
#ifndef LETTERMAN_H
#define LETTERMAN_H

#include <string>
#include <vector>
#include <iostream>
#include <getopt.h>
#include <deque>
#include <queue>

using namespace std;

class Letterman {
    private:
        class Entry {
            private:
                string word;

                bool isDiscovered;
                //will need more members eventually
            public:
                Entry() {
                    word = "";
                    isDiscovered = false;
                } //default ctor
                
                Entry(string &entryWord) {
                    word = entryWord;
                    isDiscovered = false;
                } //non-default ctor

                string getWord() {
                    return word;
                }

                void discovered() {
                    isDiscovered = true;
                }

                bool isDisc() {
                    return isDiscovered;
                }
        }; //Entry

        bool isStack;
        //true = stack
        //false = queue

        string start;
        size_t startIndex;

        string target;

        bool isWordFormat;
        //true = word format
        //false = modification format

        bool isChange;

        bool isDelete;

        bool isInsert;

        bool isSwap;

    public:
        Letterman();

        void getOptions(int argc, char** argv);
        
        vector<Entry> entries;
        
        deque<size_t> sc;

        queue<size_t> backtrace;

        bool dictContainsStart;
        bool dictContainsTarget;

        void setIsStack(bool stackBool);
        void setStart(string startString);
        void setTarget(string targetString);
        void setOutput(bool outputBool);
        void setChange(bool changeBool);
        void setLength(bool lengthBool);
        void setSwap(bool swapBool);

        void readDict();

        void search();
        bool changeSimilar(string currWord, string invWord);

        void output();
};

#endif