# include <climits>
# include <iostream>
using namespace std;

/**
 * Problem 132
 * Problem 19/45 of May 2026
 * Maximum Sum BST in Binary Tree: HARD
 * Date: 21/05/26
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
    struct NodeInfo {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;

        NodeInfo (bool bst, int s, int minV, int maxV) 
            : isBST(bst), sum(s), minVal(minV), maxVal(maxV) {}
    };

    int maxSum;

    NodeInfo dfs(TreeNode* root) {
        if (!root) {
            return NodeInfo{true, 0, INT_MAX, INT_MIN};
        }

        NodeInfo left = dfs(root->left);
        NodeInfo right = dfs(root->right);

        // check if current subtree is bst
        if (left.isBST && right.isBST && left.minVal < root->val && right.minVal > root->val) {
            int currentSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);

            return NodeInfo {
                true,
                currentSum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            }
        }

        else {
            // not a BST
            return NodeInfo(false, 0, 0, 0);
        }
    }


public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        dfs(root);
        return maxSum;
    }
};