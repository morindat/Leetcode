# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

// Problem 112
// Problem 21 of April
// Path Sum II: MEDIUM
// Date: 19/04/26
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
    void flatten(TreeNode* root) {
        TreeNode* current = root;

        while (current) {
            if (current->left) {
                // find the rightmost node in the left subtree
                TreeNode* rightMost = current->left;

                while (rightMost->right) {
                    rightMost = rightMost->right;
                }

                // connect rightMost right to current right
                rightMost->right = current->right;

                // move left subtree to right
                current->right = current->left;
                current->left = nullptr;
            }

            // advance ptr
            current = current->right;
        }
    }
};