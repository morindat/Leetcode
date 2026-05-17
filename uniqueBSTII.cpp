# include <vector>
using namespace std;

// Problem 107
// Problem 16 of April
// Unique Binary Search Tree II: MEDIUM
// Date: 14/04/26
// Complexity: O(Exponential)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Sotution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> result;

        // base case, no nodes in that range, nullptr
        if (start > end){
            result.push_back(nullptr);
            return result;
        }

        // try each number as the root
        for (int i = start; i <= end; i++) {
            // generate all posible right and left subtrees
            vector<TreeNode*> left = generate(start, i-1);
            vector<TreeNode*> right = generate(i+1, end);

            // combine each left and right subtrees
            // basically make a new root
            // attach the left and right subtree
            // push the root to the result
            for (TreeNode* l : left){
                for (TreeNode* r : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};

// Memo optimized
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        // Memoization cache
        vector<vector<vector<TreeNode*>>> memo(n + 2, 
            vector<vector<TreeNode*>>(n + 2));
        return generate(1, n, memo);
    }
    
private:
    vector<TreeNode*> generate(int start, int end, 
                               vector<vector<vector<TreeNode*>>>& memo) {
        vector<TreeNode*> result;
        
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        
        // Return cached result if available
        if (!memo[start][end].empty()) {
            return memo[start][end];
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generate(start, i - 1, memo);
            vector<TreeNode*> rightTrees = generate(i + 1, end, memo);
            
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        
        memo[start][end] = result;
        return result;
    }
};