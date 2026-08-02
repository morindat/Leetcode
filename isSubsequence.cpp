#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 196
 * Is Subsequence: EASY
 * Time: 2026-08-02 
 * Time Complexity: 0(n)  
 */ 

/*
* So here we are given two strings, s and t 
* And what we basically need to determine is if s is a Subsequence of t 
* And a Subsequence is nothing but a string that can be formed into s by removing some of chars in t, can also be none 
* Solution? Two pointers
* Start at the first chars of both sequences, if they are same char, then i++ (counter for s), and always increment j
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;  // pointer for s
        int j = 0;  // pointer for t
        
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;  // match found, move s pointer
            }
            j++;  // always move t pointer
        }
        
        return i == s.length();  // all characters in s matched
    }
};

// The follow up is however not EASY

class Followup {
private:
    vector<vector<int>>nextPos;

public:
    Followup(string t) {
        int n = t.length();
        nextPos.assign(n + 1, vector<int>(26, -1));

        for (int i = n - 1; i >= 0; i--) {
            nextPos[i] = nextPos[i + 1];
            nextPos[i][t[i] - 'a'] = i;
        }
    }

    bool isSubsequence(string s) {
        int pos = 0;

        for (char c : s) {
            int next = nextPos[pos][c - 'a'];
            if (next == -1) return false;
            pos = next + 1;
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;  // print true/false instead of 1/0
    cout << sol.isSubsequence("abc", "ahbgdc") << endl; 
    cout << sol.isSubsequence("axc", "ahbgdc") << endl;  
    cout << sol.isSubsequence("", "ahbgdc") << endl;
    cout << sol.isSubsequence("abc", "") << endl;
    cout << sol.isSubsequence("abc", "abc") << endl;
    cout << sol.isSubsequence("abc", "ab") << endl;      

    return 0;
}
