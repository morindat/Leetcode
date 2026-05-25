# include <unordered_map>
# include <vector>
# include <string>
using namespace std;

/**
 * Problem 140
 * Problem 27/45 of May 2026
 * Find Duplicate Subtrees: MEDIUM
 * Date: 24/05/26
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
    string dfs(TreeNode* node, unordered_map<string, int>& freq, vector<TreeNode*>& res) {
        if (!node) return "#";

        string key = to_string(node->val) + "," + 
            dfs(node->left, freq, res) + "," + 
            dfs(node->right, freq, res);
        
        if (++freq[key] == 2) res.push_back(node);
        return key;
    }
public:
   vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       unordered_map <string, int> freq;
       vector<TreeNode*> res;
       dfs(root, freq, res);
       return res;
   } 
};