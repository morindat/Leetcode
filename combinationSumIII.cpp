#include <vector>
using namespace std;

/**
 * Problem 174
 * Problem 11/45 of June 2026
 * Combination Sum III: MEDIUM
 * Date: 8/06/26
 * Time Complexity: O(C(9,k) × k)
*/

class Solution {
private:
    void backtrack(int start, int k, int n, vector<int>& current, vector<vector<int>>& result) {
        // base case, we found the subset
        if (current.size() == k && n == 0) {
            result.push_back(current);
            return;
        }

        // prune, if we reach size k, but not the result
        if (current.size() == k || n < 0) {
            return;
        }

        // try each number
        for (int i = start; i <= 9; i++) {
            if (i > n) break;

            current.push_back(i);
            backtrack(i + 1, k, n - 1, current, result);
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;

        // early pruning: minimum sum with k numbers
        int minSum = k * (k + 1) / 2;
        if (n < minSum) return result;

        // Maximum sum with k largest numbers (9,8,...,9-k+1)
        int maxSum = k * (19 - k) / 2;  // 9+8+...+(9-k+1)
        if (n > maxSum) return result;

        backtrack(1, k, n, current, result);
        return result;
    }
};
