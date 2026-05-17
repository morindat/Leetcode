# include <vector>
using namespace std;

// Problem 65
// Problem 11 of March
// Permutations: MEDIUM
// Date: 06/03/26
// Complexity: O(n * n!)
// So now I owe February just 1 qns

class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& res){

        // we stop as soon as we build the first perm
        if (curr.size() == nums.size()){
            // push to the res arr
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            // if the curr we are building alr contains the num/ind we are looking at
            // then move on

            if (used[i]) continue;
            
            // if not mark it used, so we do not use it again
            // push it to curr
            used[i] = true;
            curr.push_back(nums[i]);

            // backtrack
            backtrack(nums, used, curr, res);

            // only happens when we are done building
            // so pops at curr.size() == 3
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, curr, res);

        return res;
    }
};