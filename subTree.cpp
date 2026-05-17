# include <iostream>
using namespace std;

// Problem 105
// Problem 14 of April
// Subtree Of Another Tree: EASY
// Date: 11/04/26
// Complexity: O(m*n)

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
    bool isSame(TreeNode* p, TreeNode* q){
        // both null, true
        if (!p && !q) return true;

        // one missing, false
        if (!p || !q) return false;

        // values mismatch?, false
        if (p->val != q->val){
            return false;
        }

        // recurse
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        // subroot empty?, true
        if (!subRoot) return true;

        // root empty?, false
        if (!root) return false;

        // run isSame() for the roots
        if (isSame(root, subRoot)){
            return true;
        }

        // recurse
        return isSubtree(root->left, subRoot) && isSubtree(root->right, subRoot);
    }
};