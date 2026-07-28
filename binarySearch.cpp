# include <iostream>
using namespace std;

// Problem 106
// Problem 15 of April
// Search In A Binary Search Tree: EASY
// Date: 13/04/26
// Complexity: O(log n)

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;

        TreeNode* temp = root;

        while (temp != nullptr){
            if (temp->val == val){
                return temp;
            }
            else if (temp->val > val){
                temp = temp->left;
            } else if (temp->val < val){
                temp = temp->right;
            }
        }

        return nullptr;
    }
};

/**
 * Even cleaner solution
*/

class Solution {
public: 
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            root = (root->val > val) ? root->left : root->right;
        }
        return root;
    }
};


/**
 * And recursively too!
*/

class Solution {
public: 
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;
        return (root->val > val) ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};
