# include <vector>
using namespace std;

// Problem 108
// Problem 17 of April
// Unique Binary Search Tree: MEDIUM
// Date: 13/04/26
// Complexity: O(n^2)
// Can be O(n) with direct catalan formula

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
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++){
            for (int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }

    // Catalan Formula
    int numTreesCatalan(int n) {
        long long catalan = 1;

        for (int i = 0; i < n; i++){
            catalan = catalan * 2 * (2 * i + 1) / (i + 2);
        }

        return catalan;
    }
};