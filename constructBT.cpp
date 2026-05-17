# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

// Problem 110
// Problem 19 of April
// Construct Binary Tree From Pre/In Order Traversal: MEDIUM
// Date: 17/04/26
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
private:
    unordered_map<int, int> inorderMap;  // value -> index in inorder
    int preorderIndex = 0;
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int inorderStart, int inorderEnd) {
        // Base case: no elements to process
        if (inorderStart > inorderEnd) {
            return nullptr;
        }
        
        // Current root value from preorder
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find root position in inorder
        int inorderRootIndex = inorderMap[rootVal];
        
        // Build left subtree (elements before root in inorder)
        root->left = buildTreeHelper(preorder, inorderStart, inorderRootIndex - 1);
        
        // Build right subtree (elements after root in inorder)
        root->right = buildTreeHelper(preorder, inorderRootIndex + 1, inorderEnd);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Build hashmap for O(1) lookup of root positions in inorder
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        preorderIndex = 0;
        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};