# include <climits>
# include <iostream>
using namespace std;

/**
 * Problem 125
 * Problem 12/45 of May 2026
 * Binary Tree Maximum Path Sum: HARD
 * Date: 20/05/26
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
    int maxSum;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // Get the max gains from both subtrees
        int leftGain= max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));

        // Current path
        int currentPath = root->val + leftGain + rightGain;

        // Update the global max 
        maxSum = max(maxSum, currentPath);

        // Return max gain to parent coz we only take the max gain
        return root->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }

};

/**
 *    -10
      /  \
     9   20
        /  \
       15   7

 */