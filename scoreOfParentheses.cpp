# include <string>
# include <iostream>
# include <stack>
using namespace std;

// Problem 5
// Score of Parentheses: MEDIUM
// Date: 05/1/26

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st; // good ol friend, lmao

        for (char c : s){
            if (c == '('){
                st.push(0); // an indicator of a start 
            } 
            else {
                int v = st.top();
                st.pop();

                int score = (v == 0) ? 1 : 2 * v;

                if (!st.empty()){
                    st.top() += score;
                } else {
                    st.push(score);
                }
            }
        }
        return st.top();
    }
};


/*
Explanation:

Ex: (()) = 2

Loop(1)
we seen (, add 0 to st
st = [0]

Loop(2)
we seen (
st = [0, 0]

Loop(3)
we seen )
pop the top (0) and note it 
score = 1

we need to do the following
check if the stack is empty, if true then update score using v

else we push score

since it is not empty we push score, which is now 1
st = [0, 1]


loop(4)
we seen )
now again pop the top and store it

score is updated depending on what is the top of stack, 0 then 1, otherwise times 2
top is 1, so double it = 2

the stack is not empty
so we push in the score
now stack = [0, 2]

loop(5)? opps no more loops so we return the top of stack and that is 2

*/