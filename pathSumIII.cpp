# include <unordered_map>
using namespace std;

// Problem 118
// Problem 5 of May 
// Path Sum III: MEDIUM
// Date: 13/05/26
// Complexity: O(n)
// It's officially 20 days since I last solved a leetcode
// Finals and submissions plus a whole lot of excuses
// Reality is, I owe myself over 20 problems
// And today is when I officially start trying to pay me
// 4/20 I owe

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int count = 0;
    unordered_map<long, int> prefixSum;

    void dfs(TreeNode* node, long currentSum, int target) {
        if (!node) return;

        // update current sum
        currentSum += node->val;

        // check if we have a path ending at that node that sums up to target
        if (prefixSum.find(currentSum - target) != prefixSum.end()){
            count += prefixSum[currentSum - target];
        }

        // Add current sum to prefix sum map
        prefixSum[currentSum]++;

        // recurse to children
        dfs(node->left, currentSum, target);
        dfs(node->right, currentSum, target);

        // Backtrack: remove current sum from map before returning to parent
        prefixSum[currentSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        prefixSum[0] = 1;
        dfs(root, 0, targetSum);
        return count;
    }
};