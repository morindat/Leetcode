# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

// Problem 112
// Problem 21 of April
// Path Sum II: MEDIUM
// Date: 19/04/26
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        
        dfs(root, targetSum, 0, currentPath, result);
        return result;
    }
    
private:
    void dfs(TreeNode* node, int targetSum, int currentSum, 
             vector<int>& currentPath, vector<vector<int>>& result) {
        // Base case: empty node
        if (node == nullptr) {
            return;
        }
        
        // Add current node to path
        currentPath.push_back(node->val);
        currentSum += node->val;
        
        // Check if we're at a leaf node and sum matches target
        if (node->left == nullptr && node->right == nullptr) {
            if (currentSum == targetSum) {
                result.push_back(currentPath);
            }
        } else {
            // Continue DFS on children
            dfs(node->left, targetSum, currentSum, currentPath, result);
            dfs(node->right, targetSum, currentSum, currentPath, result);
        }
        
        // Backtrack: remove current node from path
        currentPath.pop_back();
    }
};