# include <stack>
# include <string>
# include <cctype>
using namespace std;

// Problem 53
// Problem 23 of Feb
// Basic Calculator II: MEDIUM
// Date: 25/02/26

class Solution {
public: 
    int calculate(string s){
        stack<int> st;
        int num = 0;
        char op = '+';
        int n = s.size();

        for (int i = 0; i < n; i++){
            char ch = s[i];
            
            // if the char we are looking at is a number
            // then build the number
            if (isdigit(ch)){
                num = num * 10 + (ch - '0');
            }

            // if it is not a number or
            // we are at the end of the string then we need to process
            if ((!isdigit(ch) && !isspace(ch)) || i == n - 1){
                if (ch == '+') st.push(num);
                else if (ch == '-') st.push(-num);
                else if (ch == '*'){
                    int top = st.top(); st.pop();
                    st.push(top * num);
                }
                else if (ch == '/'){
                    int top = st.top(); st.pop();
                    st.push(top / num);
                }

                op = ch;
                num = 0;
            }
        }

        int result = 0;
        while (!st.empty()){
            result += st.top();
            st.pop();
        }

        return result;
    }
};