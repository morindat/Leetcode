#include <vector>
#include <string>
using namespace std;

/**
 * Problem 187
 * Problem 24/45 of June 2026
 * Generate Parentheses: MEDIUM
 * Date: 16/06/26
 * Time Complexity: O(2^2n)
*/

class Solution {
private:
    void generate(int n, int open, int close, string& current, vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        if (open < n) {
            current.push_back('(');
            generate(n, open + 1, close, current, result);
            current.pop_back();
        }
        
        if (close < open) {
            current.push_back(')');
            generate(n, open, close + 1, current, result);
            current.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate(n, 0, 0, current, result);
        return result;
    }
};