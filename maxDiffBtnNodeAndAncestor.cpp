# include <iostream>
using namespace std;

/**
 * Problem 122
 * Problem 9/45 of May 2026
 * Maximum Difference Between Node & Ancestor: Medium 
 * Date: 19/05/26
 * Time Complexity: O(n);
 */

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
    void dfs(TreeNode* node, int minVal, int maxVal, int& ans) {
        if (!node) return;

        ans = max(ans, abs(node->val - minVal));
        ans = max(ans, abs(node->val - maxVal));

        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        dfs(node->left, minVal, maxVal, ans);
        dfs(node->right, minVal, maxVal, ans);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, root->val, root->val, ans);
        return ans;
    }
};