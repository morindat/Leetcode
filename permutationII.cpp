#include <vector>
#include <algorithm>
using namespace std;

/**
 * Problem 177
 * Problem 14/45 of June 2026
 * Permutation II: MEDIUM
 * Date: 9/06/26
 * Time Complexity: O(n * n!)
*/

class Solution {
private:    
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& res) {
        if (current.size() == nums.size()) {
            res.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;

            // skip duplicates
            // if the current number is the same as the previous and the previous is not used
            // continue
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, res);

            current.pop_back();
            used[i] = false;

        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used, current, res);
        return res;
    }
};

