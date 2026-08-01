# include <queue>
# include <iostream>
using namespace std;

/**
 * Problem 121
 * Problem 8 of May 2026
 * All Nodes Distance K in Binary Tree: MEDIUM 
 * Date: 19/05/26
 * Time Complexity: O(n);
 * The number of problems I owe April and May is increasing by day
 * I do not even know how many now
 * I should do 45 this month: 8/45
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
    // Helper function to find all nodes at distance k in any subtree
    void findNodes(TreeNode* node, int distance, int k, vector<int>& result) {
        if (!node) return;

        if (distance == k) {
            result.push_back(node->val);
            return;
        }

        // Find nodes downward
        findNodes(node->left, distance + 1, k, result);
        findNodes(node->right, distance + 1, k, result);
    }

    // DFS: To find target and collect all the nodes at distance k
    int findTarget(TreeNode* node, TreeNode* target, int k, vector<int>& result) {
        if (!node) return -1;

        // found the target node?
        if (node == target) {
            // find all nodes at distance k
            findNodes(node, 0, k, result);
            return 1;
        }

        // not? search in the left & right subtrees
        int leftDist = findTarget(node->left, target, k, result);
        if (leftDist != -1) {
            // means: target node is found in the left subtree
            if (leftDist == k){
                result.push_back(node->val);
            } else if (leftDist < k) {
                // check the remaining right subtree for the distance remaining
                findNodes(node->right, leftDist + 1, k, result);
            }

            return leftDist + 1;
        }

        // Do the same for the right subtree
        int rightDist = findTarget(node->right, target, k, result);
        if (rightDist != -1) {
            // means: found target in the right subtreee
            if (rightDist == k) {
                result.push_back(node->val);
            } else if (rightDist < k) {
                findNodes(node->left, rightDist + 1, k, result);
            }

            return rightDist + 1;
        }

        // target never found?
        return -1;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};

        vector<int> result;
        findTarget(root, target, k, result);

        return result;
    }
};
