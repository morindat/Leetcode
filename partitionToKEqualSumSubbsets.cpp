#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/**
 * Problem 173
 * Problem 10/45 of June 2026
 * Partition to K Equal Sum Subsets: MEDIUM
 * Date: 8/06/26
 * Time Complexity: O(k! * n)
*/

class Solution {
private:
    bool backtrack(vector<int>& nums, vector<int>& subsets, int target, int index) {
        if (index == nums.size()) {
            return true;
        }

        // try placing the current number into each subset
        for (int i = 0; i < subsets.size(); i++) {
            // skip if adding makes it larger than target
            if (nums[index] + subsets[i] > target) {
                continue;
            }

            // skip duplicate subsets (if same run, skip)
            bool is_duplicate = false;
            for (int j = 0; j < i; j++) {
                if (subsets[j] == subsets[i]) {
                    is_duplicate = true;
                    break;
                }
            }

            if (is_duplicate) continue;

            // place the current number to subset
            subsets[i] += nums[index];

            if (backtrack(nums, subsets, target, index + 1)) {
                return true;
            }

            // backtrack
            subsets[i] -= nums[index];

            // if this subset was empty and placing here failed,
            // placing in any other empty subset will also fail

            if (subsets[i] == 0) {
                return false;
            }
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % k != 0) return false;

        int target = total / k;

        // sort in descending order to fail fast
        sort(nums.begin(), nums.end(), greater<int>());

        // If any single number > target, impossible
        if (nums[0] > target) return false;

        vector<int> subsets(k, 0);
        return backtrack(nums, subsets, target, 0);
    }
};