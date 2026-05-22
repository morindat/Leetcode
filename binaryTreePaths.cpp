# include <vector>
# include <string>
# include <iostream>
using namespace std;

/**
 * Problem 133
 * Problem 20/45 of May 2026
 * Binary Tree Paths: EASY
 * Date: 22/05/26
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
    vector<string> result;
    vector<int> currentPath;

    void dfs(TreeNode* node) {
        if (!node) return;

        // add the current node to path
        currentPath.push_back(node->val);

        // if leaf, add to res
        if (!node->left && !node->right) {
            string path = to_string(currentPath[0]);

            for (int i = 1; i < currentPath.size(); i++) {
                path += "->" + to_string(currentPath[i]);
            }

            result.push_back(path);
        } else {
            // recurse to children
            dfs(node->left);
            dfs(node->right);
        }

        // backtrack: remove the last node
        currentPath.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return result;
    }
};

/**
example dry run: 
            1
           / \
           2 3
           \
            5

dfs(1) called
currentPath = [] 
→ push(1) → [1]
  ├─ not leaf
  ├─ dfs(2)
  │  → push(2) → [1,2]
  │    ├─ not leaf
  │    ├─ dfs(5)
  │    │  → push(5) → [1,2,5]
  │    │    ├─ leaf! → build "1->2->5"
  │    │    └─ pop_back() → [1,2]
  │    └─ dfs(nullptr) → return
  │    └─ pop_back() → [1]
  └─ dfs(3)
     → push(3) → [1,3]
       ├─ leaf! → build "1->3"
       └─ pop_back() → [1]
  └─ pop_back() → []
 */