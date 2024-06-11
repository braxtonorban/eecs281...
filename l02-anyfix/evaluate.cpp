// Project identifier: 1CAEF3A0FEDD0DEC26BA9808C69D4D22A9962768

#include "evaluate.hpp"
#include <cstdint>
#include <string>
#include <stack>

using namespace std;

int64_t charToInt64t(char c);

int64_t evaluate(string const& expression) {
    // make an adt containing numbers
    stack<int64_t> nums;
    
    // make an adt containing optors
    stack<char> optors;

    // read the expression into things
    for (uint16_t i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) {
            nums.push(charToInt64t(expression[i]));
        }
        else {
            optors.push(expression[i]);
        }

        // if you can make an operation: do it and put the result in nums
        if (nums.size() >= 2 && optors.size() >= 1) {
            int64_t result;
            int64_t temp = nums.top();
            nums.pop();

            if (optors.top() == '+') {
                result = nums.top() + temp;
                nums.pop();
                nums.push(result);
                optors.pop();
            }
            else if (optors.top() == '-') {
                result = nums.top() - temp;
                nums.pop();
                nums.push(result);
                optors.pop();
            }
            else if (optors.top() == '*') {
                result = nums.top() * temp;
                nums.pop();
                nums.push(result);
                optors.pop();
            }
            else if (optors.top() == '/') {
                result = nums.top() / temp;
                nums.pop();
                nums.push(result);
                optors.pop();
            }
            else {
                exit(1);
            }
        }
        
        // if you can't: keep going
    }

    // return the answer 
    return nums.top();
}

int64_t charToInt64t(char c) {
    return c - 48;
}