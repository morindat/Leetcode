#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Problem 202
 * Minimum Path Sum: MEDIUM
 * Time: 2026-08-07  
 * Complexity: 0(n)
 */ 

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        // edge case: string starts with 0
        if (s[0] == '0') return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1; // for the empty string case 
        dp[1] = 1; // for a valid char

        for (int i = 2; i <= n; i++) {
            // either take one digit out 
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }

            // or take two out
            int twoDigits = stoi(s.substr(i-2, 2));
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    string str = "10";

    cout << "Decode ways: " << sol.numDecodings(str) << endl;

    return 0;
}
