# include <vector>
using namespace std;

// Problem 90
// Problem 36 of March
// Remove One Element To Make The Array Strictly Increasing: HARDEST EASY lol.
// Date: 29/03/26
// Complexity: O(n)

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        // count for violations
        int removed = 0;

        for (int i = 0; i < nums.size() - 1; i++){
            // find the breakage
            // meaning the current number is bigger than the next
            if (nums[i] >= nums[i + 1]){
                removed++;

                // if violations are move than 1, return false
                if (removed > 1) return false;

                // so what happens when you encounter a violation
                // we need to restart the algo
                // but from where?
                // so we need the exact place of breakage

                if (i > 0 && nums[i - 1] >= nums[i + 1]){
                    nums[i + 1] = nums[i];
                }
            }
        }

        return true;
    }
};