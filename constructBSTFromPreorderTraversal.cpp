# include <climits>
# include <vector>
using namespace std;

/**
 * Problem 143
 * Problem 30/45 of May 2026
 * Construct Binary Search Tree from Preorder Traversal: MEDIUM
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
    int index = 0;

    TreeNode* build(vector<int>& preorder, int upperbound) {
        if (index >= preorder.size()) return nullptr;

        int val = preorder[index];

        // If current val > upperbound, it does not belong here
        if (val > upperbound) return nullptr;

        // use this val as a root
        index++;
        TreeNode* root = new TreeNode(val);

        // left subtree must be less than val
        root->left = build(preorder, val);

        // right subtree must be > val
        root->right = build(preorder, upperbound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};