# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

// Problem 111
// Problem 20 of April
// Construct Binary Tree From Post/In Order Traversal: MEDIUM
// Date: 18/04/26
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
    int postorderIndex;
    
    TreeNode* buildTreeHelper(vector<int>& postorder, int inorderStart, int inorderEnd) {
        // Base case: no elements to process
        if (inorderStart > inorderEnd) {
            return nullptr;
        }
        
        // Current root value from postorder (from the end)
        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find root position in inorder
        int inorderRootIndex = inorderMap[rootVal];
        
        // Build RIGHT subtree FIRST (crucial difference from preorder)
        // Right subtree elements are after root in inorder
        root->right = buildTreeHelper(postorder, inorderRootIndex + 1, inorderEnd);
        
        // Build LEFT subtree (elements before root in inorder)
        root->left = buildTreeHelper(postorder, inorderStart, inorderRootIndex - 1);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Build hashmap for O(1) lookup of root positions in inorder
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        // Start from the last element of postorder
        postorderIndex = postorder.size() - 1;
        
        return buildTreeHelper(postorder, 0, inorder.size() - 1);
    }
};