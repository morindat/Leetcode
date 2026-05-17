// Problem 114
// Problem 1 of May
// Sum Root to Leaf Numbers: MEDIUM
// Date: 13/05/26
// Complexity: O(n)
// It's officially 20 days since I last solved a leetcode
// Finals and submissions plus a whole lot of excuses
// Reality is I owe myself over 20 problems
// And today is when I officially start trying to pay me
// 1/20 I owe

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * I ain't gon lie, this was harder than I thought it was
 * The solution was a lot easier than i thought it would be
 * But the trick really is was to build the sum using a running current sum
 * And then add both the left and right of the tree to the current sum
*/



class Solution {
public:
    int dfs (TreeNode* node, int sum){
        if (!node) return 0;

        // current sum
        sum = sum * 10 + node->val;

        // isleaf? return sum
        if (!node->left && !node->right){
            return sum;
        }

        // recurse both sides
        return dfs(node->left, sum) + dfs(node->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, 0);
    }
};