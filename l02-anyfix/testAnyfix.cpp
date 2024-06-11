// Project identifier: 1CAEF3A0FEDD0DEC26BA9808C69D4D22A9962768

#include <iostream>
#include <string>
#include "evaluate.hpp"
#include <utility>

using namespace std;

auto main() -> int {
    cout << "Test 1: ";
    if (evaluate("+12") == 3) {
        cout << "success\n";
    }
    else {
        cout << "fail\n";
    }

    cout << "Test 2: ";
    if (evaluate("3*4") == 12) {
        cout << "success\n";
    }
    else {
        cout << "fail\n";
    }

    cout << "Test 3: ";
    if (evaluate("56-") == -1) {
        cout << "success\n";
    }
    else {
        cout << "fail\n";
    }

    cout << "Test 4: ";
    if (evaluate("321-/") == 3) {
        cout << "success\n";
    }
    else {
        cout << evaluate("321-/") << " ";
        cout << "fail\n";
    }

    cout << "Test 5: ";
    if (evaluate("1-2*3") == -3) {
        cout << "success\n";
    }
    else {
        cout << evaluate("1-2*3") << " ";
        cout << "fail\n";
    }

    cout << "Test 6: ";
    if (evaluate("*+456") == 54) {
        cout << "success\n";
    }
    else {
        cout << evaluate("*+456") << " ";
        cout << "fail\n";
    }
}

/*
 * NOTE: Since this file's name matches the glob pattern test*.cpp, the file is
 * a test file, NOT a source file! Nothing written here will be
 * submitted to the autograder.
 *
 * This also means there is no executable for this lab. Do not set EXECUTABLE
 * in your makefile to anything intended to be meaningful. Do not build with
 * `make release` or `make debug` or `make all` or just plain `make`; instead,
 * run `make help` and read the output that gives you, then use what you learn
 * from that to figure out how to build a test executable using this file.
 */
