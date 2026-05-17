# include <unordered_map>
# include <vector>
using namespace std;

// Problem 119
// Problem 5 of May 
// Most Frequent Subtree Sum: MEDIUM
// Date: 15/05/26
// Complexity: O(n)
// It's officially 20 days since I last solved a leetcode
// Finals and submissions plus a whole lot of excuses
// Reality is, I owe myself over 20 problems
// And today is when I officially start trying to pay me
// 4/20 I owe

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
    unordered_map<int, int> freq; // sum -> freq
    int maxFreq = 0;

    int postorder(TreeNode* node) {
        if (!node) return 0;

        // calculate subtrees sum
        int leftSum = postorder(node->left);
        int rightSum = postorder(node->right);
        int total = node->val + leftSum + rightSum;

        // record
        freq[total]++;
        maxFreq = max(maxFreq, freq[total]);

        return total;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};

        postorder(root);

        // collect all the max
        vector<int> result;

        for (auto &[sum, count]: freq) {
            if (count == maxFreq) {
                result.push_back(sum);
            }
        }

        return result;
    }
};