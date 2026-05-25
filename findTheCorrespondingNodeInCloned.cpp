# include <queue>
using namespace std;

/**
 * Problem 146
 * Problem 33/45 of May 2026
 * Find a Corresponding Node of a Binary Tree in a Clone of That Tree: EASY
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
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original || original == target) {
            return cloned;
        }
        
        auto leftResult = getTargetCopy(original->left, cloned->left, target);
        if (leftResult) return leftResult;
        
        return getTargetCopy(original->right, cloned->right, target);
    }
};

// Less optimal solution, and perhaps incorrect sometimes

class Solution {
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!target || !cloned || !original) return nullptr;

        int node_val = target->val;

        queue<TreeNode*> q;
        q.push(cloned);

        while (!q.empty()) {
            int level_size = q.size();

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int value = node->val;

                if (node_val == value){
                    return node;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right); 
            } 
        }
        return nullptr;
    }
};