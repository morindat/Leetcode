#include <vector>
using namespace std;

/**
 * Problem 169
 * Problem 6/45 of June 2026
 * Combination Sum: MEDIUM
 * Date: 3/06/26
 * Time Complexity: O(n^)
*/

class Solution {
private:
    void findCombinations(vector<int> nums, int target, vector<int>& current, vector<vector<int>>& result, int start) {
        // base case: found valid combination
        if (target == 0) {
            result.push_back(current);
        }

        // base case: we did not
        if (target < 0) {
            return;
        }

        // try all combinations from start
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);

            // recurse with that same elemento
            findCombinations(nums, target - nums[i], current, result, i);

            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        findCombinations(candidates, target, current, result, 0);
        
        return result;
    }
};