#include <vector>
#include <string>
using namespace std;

/**
 * Problem 189
 * Problem 26/45 of June 2026
 * Palindrome Partitioning: MEDIUM
 * Date: 27/06/26
 * Time Complexity: O(n * 2^n)
*/

class Solution {
private:
    // checks palindrome in 0(n) time
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, int start, vector<string>& current, vector<vector<string>>& res) {
        if (start == s.length()) {
            res.push_back(current);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                // choose it
                current.push_back(s.substr(start, i - start + 1));

                // explore
                backtrack(s, i + 1, current, res);

                // remove it
                current.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>> res;
        backtrack(s, 0, current, res);
        return res;
    }
};