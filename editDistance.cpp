#include <bits/stdc++.h>
using namespace std;

/*
 * Problem 216
 * Edit Distance; MEDIUM
 * Date: 21/09/2026
 * Complexity: O() 
 */ 

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        // dp[i][j] = min ops to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases
        for (int i = 0; i <= m; i++) dp[i][0] = i; // delete all of word1
        for (int j = 0; j <= n; j++) dp[0][j] = j; // insert all of word2

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]; // chars match, no cost
                } else {
                    dp[i][j] = 1 + min({
                        dp[i-1][j-1], // replace
                        dp[i-1][j],   // delete from word1
                        dp[i][j-1]    // insert into word1
                    });
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";

    cout << "Min Distance: " << sol.minDistance(word1, word2) << endl;

    return 0;
}
