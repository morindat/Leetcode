# include <iostream>
using namespace std;

/**
 * Problem 154
 * Problem 41/45 of May 2026
 * Symmetric Tree: EASY
 * Date: 27/05/26
 * Time Complexity: O(n);
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    bool isSame(TreeNode* l, TreeNode* r) {
        if(!l && !r) return true;
        if (!l || !r) return false;

        if (l->val != r->val) {
            return false;
        }

        return isSame(l->left, r->right) && isSame(l->right, r->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
};