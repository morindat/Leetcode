# include <algorithm>
using namespace std;

/**
 * Problem 161
 * Problem 48/45 of May 2026
 * Convert Sorted Array To BST: EASY
 * Date: 30/05/26
 * Time Complexity: O(log n)
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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;  // Left subtree unbalanced
        
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Right subtree unbalanced
        
        // Check if current node is balanced
        if (abs(leftHeight - rightHeight) > 1) return -1;
        
        // Return height if balanced
        return 1 + max(leftHeight, rightHeight);
    }
};