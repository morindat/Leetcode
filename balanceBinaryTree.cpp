# include <algorithm>
using namespace std;

/**
 * Problem 163
 * Problem 50/45 of May 2026
 * Balanced Binary Tree: EASY
 * Date: 30/05/26
 * Time Complexity: O(n)
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
public:
    int height (TreeNode* root){
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(lh - rh) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};