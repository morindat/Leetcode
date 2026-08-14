#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Problem 207
 * Longest Increasing Subsequence: MEDIUM
 * Time: 2026-08-14
 * Complexity: 0(n^2) and 0(n log n) 
 */ 

/*
 * dp[i] = length of the longest increasing subsequence ending at i.
 * dp[i] = 1 + max(dp[j]) for all j < i with nums[j] < nums[i].
 * For the O(n log n) version we keep tails[i] = smallest possible tail
 * value of an increasing subsequence of length i+1, and replace/append
 * using lower_bound.
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }

    int lengthOfLIS_binary(vector<int>& nums) {
        vector<int> tails;

        for (const int& x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }

        return tails.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Length: " << sol.lengthOfLIS(nums) << endl;
    cout << "Length (binary search): " << sol.lengthOfLIS_binary(nums) << endl;

    return 0;
}
