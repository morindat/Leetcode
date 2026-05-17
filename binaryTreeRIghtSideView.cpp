# include <vector>
# include <queue>
using namespace std;

// Problem 115
// Problem 2 of May 
// Sum Root to Leaf Numbers: MEDIUM
// Date: 13/05/26
// Complexity: O(n)
// It's officially 20 days since I last solved a leetcode
// Finals and submissions plus a whole lot of excuses
// Reality is I owe myself over 20 problems
// And today is when I officially start trying to pay me
// 2/20 I owe

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                // If this is the last node in this level (rightmost)
                if (i == levelSize - 1) {
                    result.push_back(curr->val);
                }
                
                // Add children from left to right (so rightmost is last)
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        
        return result;
    }
};