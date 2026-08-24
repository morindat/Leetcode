#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 210
 * Partition Equal Subset Sum: MEDIUM
 * Time: 08/24/2026
 * Complexity: O(target) 
 */ 

class Solution {
private:
    // Not good enough for Leetcode, exceeds time limit
    bool dfs(vector<int>& nums, int target, int start) {
        if (target == 0) return true;
        if (target < 0) return false;

        for (int i = start; i < nums.size(); i++) {
            if (dfs(nums, target - nums[i], i+1)) {
                return true;
            }
        }

        return false;
    }

public:
    bool canPartitionDFS(vector<int>& nums) {
        int sum = 0;

        for (int num: nums) {
            sum += num;
        }

        if (sum % 2 != 0) return false;

        return dfs(nums, sum/2, 0);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) return false;
        int target = sum / 2;

        vector<int> dp (target + 1, false);
        dp[0] = true;

        for (int num: nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            } 
        }
        
        return dp[target];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,5,11,5};

    if (sol.canPartition(nums)) {
        cout << "True" << endl;
    } else {
        cout << "False";
    }

    return 0;
}
