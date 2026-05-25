# include <queue>
using namespace std;

/**
 * Problem 139
 * Problem 26/45 of May 2026
 * Find Bottom Left Tree Value: MEDIUM
 * Date: 24/05/26
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftmost = root->val;

        while (!q.empty()) {
            int levelSize = q.size();
            leftmost = q.front()->val; // First node in this level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return leftmost;
    }
};