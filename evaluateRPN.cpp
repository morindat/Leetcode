# include <string>
# include <stack>
# include <vector>
using namespace std;

// Problem 4
// Evaluate RPN: MEDIUM
// Date: 04/1/26

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string tkn : tokens){
            if (tkn == "+" || tkn == "-" || tkn == "/" || tkn == "*"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (tkn == "+") st.push(a + b);
                else if (tkn == "-") st.push(a - b);
                else if (tkn == "*") st.push(a * b);
                else if (tkn == "/") st.push(a / b);
            }

            else {
                st.push(stoi(tkn));
            }
        }
        return st.top();
    }
};

/*

Explanaation? Perhaps the easiest MID problem that i ever solved in leetcode
- All we need to do is, push all operands into the stack
- As soon we seen an operator, pop the first two elements in the stack and push the evaluation
- Return the st.top();

*/
