#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Problem 204
 * Word Break: MEDIUM
 * Time: 2026-08-10
 * Complexity: 0(n * m * L)
 * n = length of s, m = size of wordDict, L = average word length
 */ 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        // dp[i] = true if s[0..i-1] can be segmented into dictionary words
        vector<bool> dp(n + 1, false);
        dp[0] = true; // empty string is always segmentable

        for (int i = 1; i <= n; i++) {
            // try to end a dictionary word at position i
            for (const string& w : wordDict) {
                int len = w.size();

                if (i >= len && dp[i - len] && s.substr(i - len, len) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    string s1 = "leetcode";
    vector<string> dict1 = {"leet", "code"};
    cout << "Word break (leetcode): " << (sol.wordBreak(s1, dict1) ? "true" : "false") << endl;

    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};
    cout << "Word break (applepenapple): " << (sol.wordBreak(s2, dict2) ? "true" : "false") << endl;

    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Word break (catsandog): " << (sol.wordBreak(s3, dict3) ? "true" : "false") << endl;

    return 0;
}
