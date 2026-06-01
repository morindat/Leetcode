#include <algorithm>
#include <vector>
using namespace std;

/**
 * Problem 164
 * Problem 1/45 of June 2026
 * Maximum Subarray: MEDIUM
 * Date: 1/06/26
 * Time Complexity: O(n)
*/

class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(currentSum, maxSum);
        }

        return maxSum;
    }
};