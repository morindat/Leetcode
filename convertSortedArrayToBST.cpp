# include <vector>
using namespace std;

/**
 * Problem 161
 * Problem 48/45 of May 2026
 * Convert Sorted Array To BST: EASY
 * Date: 30/05/26
 * Time Complexity: O(log n)
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
    TreeNode* buildBST(vector<int>& nums, int left, int right){
        if (left > right) return NULL;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode();
        node->val = nums[mid];
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);
        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};