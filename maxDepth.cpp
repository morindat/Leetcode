// Problem 99
// Problem 8 of April
// Max Depth Of Binary Tree: EASY
// Date: 08/04/26
// Complexity: O(n)

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
    int height(TreeNode* root){
        if (root == nullptr) return 0;

        int leftHeight = 1 + height(root->left);
        int rightHeight = 1 + height(root->right);

        return leftHeight > rightHeight? leftHeight : rightHeight;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        return height(root);
    }
};