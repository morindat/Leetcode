#include <vector>
#include <algorithm>
using namespace std;

/**
 * Problem 170
 * Problem 7/45 of June 2026
 * Combination: MEDIUM
 * Date: 3/06/26
 * Time Complexity: O(C(n, k) * k)
*/

class Solution {
private:    
    void backtrack(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(n, k, i+1, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(n, k, 1, current, result);
        return result;
    }
};