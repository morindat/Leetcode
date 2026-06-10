#include <vector>
#include <string>
using namespace std;

/**
 * Problem 180
 * Problem 17/45 of June 2026
 * Letter Case Permutation: MEDIUM
 * Date: 10/06/26
 * Time Complexity: O(k)
*/

class Solution {
private:
    void backtrack(string& s, int index, vector<string>& res) {
        if (index == s.length()) {
            res.push_back(s);
            return;
        }

        // If current character is a digit, just move forward
        if (isdigit(s[index])) {
            backtrack(s, index + 1, res);
        } else {
            // Try lowercase
            s[index] = tolower(s[index]);
            backtrack(s, index + 1, res);

            // Try uppercase
            s[index] = toupper(s[index]);
            backtrack(s, index + 1, res);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        backtrack(s, 0, result);
        return result;
    }
};