# include <vector>
# include <queue>
using namespace std;

// Problem 108
// Problem 17 of April
// Level Order Traversal Of Binary Search Tree: MEDIUM
// Date: 15/04/26
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push({root});

        while (!q.empty()){
            int qsize = q.size();
            vector<int> nodes;

            for (int i = 0; i < qsize; i++){
                TreeNode* node = q.front();
                q.pop();

                nodes.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(nodes);
        }

        return result;

    }
};