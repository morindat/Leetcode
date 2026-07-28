# include <iostream>
using namespace std;

/**
 * Problem 144
 * Problem 31/45 of May 2026
 * BST To Greater Sum Tree: MEDIUM
 * Date: 25/05/26
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
    int sum = 0;

public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return nullptr;

        // Well, the key and only realization here is that
        // Only nodes in the right could be greater than the current node
        // So why node reverse inorder?

        bstToGst(root->right);

        sum += root->val;
        root->val = sum;

        bstToGst(root->left);

        return root;
    }
};
