#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Problem 215
 * Longest Common Subsequence: MEDIUM
 * Date: 13/09/2026
 * Complexity: O(n*m) 
 */ 


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // Create a DP table 
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        //Fill the DP table 
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // Characters match 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";

    cout << "LCS: " << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}

