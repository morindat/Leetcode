# include <iostream>
using namespace std;

/**
 * Problem 142
 * Problem 29/45 of May 2026
 * Distribute Coins In Binary Tree: MEDIUM
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
    int moves = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftExcess = dfs(node->left);
        int rightExcess = dfs(node->right);

        // Current node's excess = (its coin + excess from children) - 1
        int excess = node->val + leftExcess + rightExcess - 1;

        // Each excess coin must move across this edge (absolute value)
        moves += abs(excess);

        return excess;
    }

public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};