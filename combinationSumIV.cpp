#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 210
 * Combination Sum IV: MEDIUM
 * Time: 23/08/2026
 * Complexity: O(target * n) time, O(target) space
 */ 

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[x] = number of sequences that sum to exactly x.
        // Use unsigned int because intermediate dp values can exceed INT_MAX
        // even when the final answer fits in 32 bits; unsigned overflow is
        // well-defined and still gives the exact final answer.
        vector<unsigned int> dp(target + 1, 0);

        // Base case: there is exactly one empty sequence that sums to 0.
        dp[0] = 1;

        // Build answers for every sum from 1 to target.
        // "Combination Sum IV" actually counts sequences, so ORDER MATTERS:
        // any sequence summing to i has a unique last element num, and the
        // prefix before it is a valid sequence summing to i - num. Adding
        // dp[i - num] for every possible last element counts each sequence
        // exactly once.
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                // We can append num only if the remaining sum is non-negative.
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    int target = 4;
    cout << "Combinations: " << sol.combinationSum4(nums, target) << endl;

    return 0;
}

