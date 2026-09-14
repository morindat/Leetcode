#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
 * Problem 214
 * Palindrome Substrings: MEDIUM
 * Time: 09/08/2026
 * Complexity: O(n*m) 
 */ 

class Solution {

public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp (n, vector<bool>(n, false));
        int count = 0;

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};

class Solution2 {
private:
    int n;
    string s;

    int expand(int left, int right) {
        int count = 0;

        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }

public:
    int countSubstrings(string str) {
        s = str;
        n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += expand(i, i);
            count += expand(i, i + 1);
        }

        return count;
    }
};

int main() {
    Solution sol;
    string s = "aaa";

    cout << "Palindromic Substrings: " << sol.countSubstrings(s) << endl;

    return 0;
}



