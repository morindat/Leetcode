# include <stack>
# include <string>
using namespace std;

/**
 * Problem 130
 * Problem 17/45 of May 2026
 * Recover a Tree From Preorder Traversal: HARD
 * Date: 20/05/26
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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st;
        int i = 0;
        int n = traversal.length();
        TreeNode* root = nullptr;
        
        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }
            
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }
            
            TreeNode* node = new TreeNode(value);
            
            if (depth == 0) {
                root = node;  // This is the root
            } else {
                while (!st.empty() && st.top().second >= depth) {
                    st.pop();
                }
                TreeNode* parent = st.top().first;
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
            
            st.push({node, depth});
        }
        
        return root;
    }
};