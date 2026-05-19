# include <iostream>
using namespace std;

/**
 * Problem 124
 * Problem 11/45 of May 2026
 * Recover Binary Search Tree: Medium 
 * Date: 19/05/26
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
    // We need to keep track of these ptrs
    // {first: first node to break the bst invariant; second: second node to do so; prev: prev node in traversal}
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if(!root) return;

        // go left
        inorder(root->left);

        // look for violation
        if (prev && prev->val > root->val) {
            // found a violation
            if (!first) {
                first = prev;
            }

            second = root;
        }

        prev = root;

        // go right
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Find the two swapped nodes
        inorder(root);
        
        // Swap their values back
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};

// Example: [3,1,4,null,null,2]
// Tree structure:
//      3
//     / \
//    1   4
//       /
//      2

// Inorder traversal process:
// Step 1: Go left to node 1
// prev = null, root = 1
// No violation, set prev = 1

// Step 2: Back to node 3
// prev = 1, root = 3
// Check: 1 > 3? No ✓
// prev = 3

// Step 3: Go to node 4's left child (node 2)
// root = 2, prev = 3
// Check: 3 > 2? YES! Violation found
// first = 3, second = 2
// prev = 2

// Step 4: Back to node 4
// root = 4, prev = 2
// Check: 2 > 4? No ✓

// After traversal: first=3, second=2
// Swap: 3 ↔ 2

// Result tree:
//      2
//     / \
//    1   4
//       /
//      3