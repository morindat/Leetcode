# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

// Problem 117
// Problem 4 of May 
// House Robber III: MEDIUM
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
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        // get results from both subtrees
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        // If we rob current node: 
        // take current value + best from children when they are NOT robbed
        int robCurrent = node->val + left.second + right.second;
        
        // If we don't rob current node:
        // take max of (rob or not rob) from each child independently
        int skipCurrent = max(left.first, left.second) + max(right.first, right.second);
        
        return {robCurrent, skipCurrent};
    }


public:
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
};