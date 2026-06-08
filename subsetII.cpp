#include <vector>
#include <algorithm>
using namespace std;

/**
 * Problem 172
 * Problem 9/45 of June 2026
 * Subset II: MEDIUM
 * Date: 8/06/26
 * Time Complexity: O(n * 2^n)
*/

class Solution {
private:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // skip duplicates in the same level
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }

            current.push_back(nums[i]);
            backtrack(nums, i+1, current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, current, result);
        return result;
    }
};