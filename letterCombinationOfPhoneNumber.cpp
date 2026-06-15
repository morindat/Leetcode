#include <vector>
#include <string>
using namespace std;

/**
 * Problem 186
 * Problem 23/45 of June 2026
 * Letter Combinations of a Phone Number: MEDIUM
 * Date: 15/06/26
 * Time Complexity: O(4^n * n)
*/

class Solution {
private:
    vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(string& digits, int index, string& current, vector<string>& res) {
        // base case: we have processed the entire string of digits
        if (index == digits.length()) {
            res.push_back(current);
            return;
        }

        // get the letter of the current index
        int digit = digits[index] - '0';
        string letters = mapping[digit];

        // try themm out
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, res);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        backtrack(digits, 0, current, result);
        return result;
    }
};