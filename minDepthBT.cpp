# include <algorithm>
using namespace std;

// Problem 101
// Problem 10 of April
// Min Depth Of Binary Tree: EASY
// Date: 09/04/26
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
    int minDepth(TreeNode* root){
        if (root == nullptr) return 0;

        // if left child missing
        // height is by right child
        if (root->left == nullptr){
            return 1 + minDepth(root->right);
        }

        // if right child missing
        // return the left child height
        if (root->right == nullptr){
            return 1 + minDepth(root->left);
        }

        // if both there, return the min of the two children
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};