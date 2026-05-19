# include <iostream>
using namespace std;

/**
 * Problem 123
 * Problem 10/45 of May 2026
 * Count Good Nodes In Binary Tree: Medium 
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
    void dfs(TreeNode* node, int maxVal, int& ans) {
        if (!node) return;
        
        // only count the nodes with values >= max val
        if (node->val >= maxVal) {
            ans++;

            // update max value
            maxVal = max(maxVal, node->val);
        }

        // go left and right
        dfs(node->left, maxVal, ans);
        dfs(node->right, maxVal, ans);
    }

public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int ans = 0; 
        dfs(root, root->val, ans);

        return ans;
    }
};