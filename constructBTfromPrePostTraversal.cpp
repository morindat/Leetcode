# include <unordered_map>
# include <vector>
# include <iostream>
using namespace std;

/**
 * Problem 121
 * Problem 8 of May 2026
 * All Nodes Distance K in Binary Tree: MEDIUM 
 * Who in they right mind labelled this MEDIUM?
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
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // Map postorder values to their indices for O(1) lookup
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }
        
        return build(preorder, 0, preorder.size() - 1,
                    postorder, 0, postorder.size() - 1, postIndex);
    }
    
private:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                   vector<int>& postorder, int postStart, int postEnd,
                   unordered_map<int, int>& postIndex) {
        
        if (preStart > preEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        if (preStart == preEnd) return root;
        
        int leftRootVal = preorder[preStart + 1];
        int leftRootIndex = postIndex[leftRootVal];
        int leftSize = leftRootIndex - postStart + 1;
        
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                          postorder, postStart, leftRootIndex, postIndex);
        
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                           postorder, leftRootIndex + 1, postEnd - 1, postIndex);
        
        return root;
    }
};