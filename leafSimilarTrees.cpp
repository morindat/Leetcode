# include <vector>
using namespace std;

// Problem 67
// Problem 13 of March
// Leaf Similar Trees
// Date: 07/03/26
// Complexity: O(n)
// Each node is visited once
// And with this, I owe nothing to Feb (All 4 qns paid off)

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
    // do a dfs traversal
    // if found a leaf, add to result
    // dfs left, then right
    
    void dfs(TreeNode* node, vector<int>& leaves){
        if (node == nullptr) return;

        if (node->left == nullptr && node->right == nullptr){
            leaves.push_back(node->val);
            return;
        }

        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;

        dfs(root1, a);
        dfs(root2, b);

        return a == b;
    }
};