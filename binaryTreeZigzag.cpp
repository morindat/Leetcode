# include <vector>
# include <queue>
using namespace std;

// Problem 109
// Problem 18 of April
// Binary Tree Zigzag Level Order Traversal: MEDIUM
// Date: 16/04/26
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        // ltr -> Left to right
        int ltr = true;

        while(!q.empty()){
            int lsize = q.size();
            vector<int> nodes;

            for (int i = 0; i < lsize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Determine position to insert based on direction
                int indx = ltr ? i : lsize- 1 - i; 
                nodes[indx] = node->val;
                
                // Add children to queue for next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Add current level to result and toggle direction
            result.push_back(nodes);
            ltr = !ltr;
        }

        return result;
    }
};