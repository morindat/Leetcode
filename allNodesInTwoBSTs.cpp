# include <vector>
using namespace std;

/**
 * Problem 145
 * Problem 32/45 of May 2026
 * All Nodes In Two BST: MEDIUM
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
private: 
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        vector<int> res;

        inorder(root1, list1);
        inorder(root2, list2);

        int i = 0, j = 0;

        while (i < list1.size() && j < list2.size()) {
            if (list1[i] < list2[j]) {
                res.push_back(list1[i]);
                i++;
            } else {
                res.push_back(list2[j++]);
            }
        }

        while (i < list1.size()) res.push_back(list1[i++]);
        while (j < list2.size()) res.push_back(list2[j++]);

        return res;
    }
};