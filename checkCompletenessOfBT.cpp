# include <queue>
using namespace std;

/**
 * Problem 141
 * Problem 28/45 of May 2026
 * Check Completeness of a Binary Tree: MEDIUM
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
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(!node) {
                foundNull = true;
            } else {
                if (foundNull) {
                    return false;
                }

                // Push both children (even if null)
                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};