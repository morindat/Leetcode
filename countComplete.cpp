# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

// Problem 116
// Problem 3 of May 
// Count Complete Tree Nodes: EASY
// Date: 13/05/26
// Complexity: O(n)
// It's officially 20 days since I last solved a leetcode
// Finals and submissions plus a whole lot of excuses
// Reality is I owe myself over 20 problems
// And today is when I officially start trying to pay me
// 3/20 I owe

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
    int getHeight(TreeNode* node) {
        int height = 0;

        while (node) {
            height++;
            node = node->left;
        }

        return height;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) + countNodes(root->right);
        } else {
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
};