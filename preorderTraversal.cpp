# include <vector>
using namespace std;

// Problem 102
// Problem 11 of April
// Preorder Traversal: EASY
// Date: 09/04/26
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
public:
    void preorder(TreeNode* root, vector<int>& res){
        if (root != nullptr){
            res.push_back(root->val);
            preorder(root->left, res);
            preorder(root->right, res);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};