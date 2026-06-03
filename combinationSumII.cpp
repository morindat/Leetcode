#include <vector>
#include <algorithm>
using namespace std;

/**
 * Problem 170
 * Problem 7/45 of June 2026
 * Combination Sum II: MEDIUM
 * Date: 3/06/26
 * Time Complexity: O(2^n)
*/

class Solution {
private: 
    void findCombinations(vector<int>& nums, int target, vector<int>& current, vector<vector<int>>& result, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }

            if (nums[i] > target) {
                break;
            }

            // Pick the current elemento
            current.push_back(nums[i]);

            // Recurse
            findCombinations(nums, target - nums[i], current, result, i+1);

            // Backtrack
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        sort(candidates.begin(), candidates.end());
        findCombinations(candidates, target, current, result, 0);
        
        return result;
    }
};