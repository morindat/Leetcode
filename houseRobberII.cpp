#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 206
 * House Robber II: MEDIUM
 * Time: 2026-08-12
 * Complexity: 0(n) 
 */ 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        auto roblinear = [&](int l, int r) {
            int prev2 = 0;
            int prev1 = 0;

            for (int i = l; i <= r; i++) {
                int current = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = current;
            }

            return prev1;
        };
        // Either exclude the last or the first one, we can not rob both
        return max(roblinear(0, n-2), roblinear(1, n-1));
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Total: $" << sol.rob(nums) << endl;

    return 0;
}
