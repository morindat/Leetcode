#include <vector>
#include <algorithm>
using namespace std;

/**
 * Problem 176
 * Problem 13/45 of June 2026
 * Count Number of Maximum Bitwise-OR Subsets: MEDIUM
 * Date: 8/06/26
 * Time Complexity: O(2^n)
*/

class Solution {
private:
    int maxOR = 0;
    int count = 0;
    
    void backtrack(vector<int>& nums, int index, int currentOR) {
        if (index == nums.size()) {
            if (currentOR == maxOR) {
                count++;
            }
            return;
        }
        
        // Skip current element
        backtrack(nums, index + 1, currentOR);
        
        // Take current element
        backtrack(nums, index + 1, currentOR | nums[index]);
    }
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // Calculate maximum OR (OR of all elements)
        for (int num : nums) {
            maxOR |= num;
        }
        
        backtrack(nums, 0, 0);
        
        // Subtract 1 if empty subset was counted (currentOR=0)
        // But empty subset only counts if maxOR == 0
        // Since nums are positive integers, maxOR > 0, so empty subset never counts
        return count;
    }
};