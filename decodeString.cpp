# include <string>
# include <iostream>
# include <stack>
using namespace std;

// Problem 3
// Decode String: MEDIUM
// Date: 03/01/26


class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string currentString = "";
        int currentNumber = 0;

        for (char c : s) {

            // Case 1: digit → build the repeat count
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }

            // Case 2: '[' → save state and reset
            else if (c == '[') {
                st.push({currentString, currentNumber});
                currentString = "";
                currentNumber = 0;
            }

            // Case 3: letter → append to current string
            else if (isalpha(c)) {
                currentString += c;
            }

            // Case 4: ']' → pop and expand
            else if (c == ']') {
                auto [prevString, repeatCount] = st.top();
                st.pop();

                string expanded = "";
                for (int i = 0; i < repeatCount; i++) {
                    expanded += currentString;
                }

                currentString = prevString + expanded;
            }
        }

        return currentString;
    }
};

// Explanation: Line by Line
/*

Example s = 3[a]
Output: aaa

We start with an empty string and num
and a stack
stack = [{}]
string = ""
num = 0;

loop (1)
    - we are looking at 3;
    - 3 is a digit, so we build a number
    - num = 3

loop (2)
    - we are looking at [
    - it is an open bracket, signifying the beginning of a deeper layer
    - push the string and num to stack
    - stack = [{"", 3}]
    - reset both num and string 
    - num = 0;
    - string = ""

loop (3)
    - we are looking at 'a'
    - now we update the string
    - string = 'a'

loop (4)
    - we are looking at ]
    - signfies the end of the deeper level
    - now we need to pop the stack
    - stack now is [{}]
    - we have the string, prev string = "" and number = 3
    - now we need to work with this number
    - we loop for number amount of times and each time we do so
    - we build a new string call it decoded and we add the string in it
    - we then update the string to prev string + decoded
    - string = "" + aaa (at this point)
    - we return this string
    - and that is the fucking answer
*/