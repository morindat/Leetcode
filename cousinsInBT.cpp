# include <queue>
using namespace std;

/**
 * Problem 135
 * Problem 22/45 of May 2026
 * Cousins In Binary Tree: EASY
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelsize = q.size();

            // parents
            TreeNode* parentX = nullptr;
            TreeNode* parentY = nullptr;

            // process the level
            for (int i = 0; i < levelsize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    if (node->left->val == x) parentX = node;
                    if (node->left->val == y) parentY = node;
                    q.push(node->left);
                }

                if (node->right) {
                    if (node->right->val == x) parentX = node;
                    if (node->right->val == y) parentY = node;
                    q.push(node->right);
                }
            }

            // both parents?
            // make sure they aint the same
            if (parentX && parentY) {
                return parentX != parentY;
            }

            // just one -> false immediately
            if (parentX || parentY) {
                return false;
            }
        }

        // else false
        return false;
    }
};