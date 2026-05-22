# include <iostream>
using namespace std;

/**
 * Problem 134
 * Problem 21/45 of May 2026
 * Range Sum Of Binary Search Tree: EASY
 * Date: 22/05/26
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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;

        int sum = 0;

        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);

        return sum;
    }
};