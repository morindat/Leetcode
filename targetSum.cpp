#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/*
 * Problem 212
 * Target Sum: MEDIUM
 * Time: 08/27/2026
 * Complexity: O(N * total sum) 
 */ 

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total) return 0;

        int offset = total;
        int max_sum = 2 * offset;

        vector<vector<int>> dp (n + 1, vector<int>(max_sum + 1, 0));
        dp[0][offset] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= max_sum; j++) {
                // Push foward: Add the current number 
                if (j + nums[i] <= max_sum) {
                    dp[i + 1][j + nums[i]] += dp[i][j];
                }

                // Push foward: Subtract the current number 
                if (j - nums[i] >= 0) {
                    dp[i + 1][j - nums[i]] += dp[i][j];
                }
            }
        }

        return dp[n][target + offset];
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << "No. of ways: " << sol.findTargetSumWays(nums, target);

    return 0;
}
