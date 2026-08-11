#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 205
 * House Robber: MEDIUM
 * Time: 2026-08-11
 * Complexity: 0(n) 
 */ 

/*
 * The only thing to notice here is that 
 * dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 * but ofcourse we can Space Optimize it so I will Iterate instead 
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;

        for (const int& num : nums) {
            int current = max(prev1, prev2+num);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Total: $" << sol.rob(nums) << endl;

    return 0;
}
