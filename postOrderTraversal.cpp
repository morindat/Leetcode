# include <vector>
using namespace std;

// Problem 103
// Problem 12 of April
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
    void postorder(TreeNode* root, vector<int>& res){
        if (root == nullptr) return;

        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    
    };
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};