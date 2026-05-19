# include <queue>
# include <iostream>
using namespace std;

/**
 * Problem 120
 * Problem 7 of May 2026
 * Maximum Width Of the Binary Tree: Medium
 * Date: 19/05/26
 * Time Complexity: O(n);
 * The number of problems I owe April and May is increasing by day
 * I do not even know how many now
 * I should do 45 this month: 7/45
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

public:
    int widthOfBinaryTree(TreeNode* root) {
        // Check for empty trees
        if (!root) return 0;

        // Queue of {node, index}
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0}); // The root is at index 0
        int maxWidth = 0; 

        // BFS
        while (!q.empty()){
            int levelSize = q.size();
            unsigned long long leftmost= q.front().second;
            unsigned long long rightmost = leftmost;

            // Process the entire level
            for (int i = 0; i < levelSize; i++) {
                auto [node, pos] = q.front();
                q.pop();

                // update rightmost of this node
                if (i == levelSize - 1) {
                    rightmost = pos;
                }

                // add children and their pos
                if (node->left) {
                    q.push({node->left, 2 * pos});
                } 

                if (node->right) {
                    q.push({node->right, 2 * pos + 1});
                }
            }

            // width at that level
            int levelWidth = rightmost - leftmost + 1;
            int maxWidth = max(maxWidth, levelWidth);
        }

        return maxWidth;
    }
};

/**
 * Pretty straight forward i'd say
 * No need for explanations
 */