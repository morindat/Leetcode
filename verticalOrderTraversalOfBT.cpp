# include <queue>
# include <algorithm>
# include <unordered_map>
# include <vector>
using namespace std;

/**
 * Problem 129
 * Problem 16/45 of May 2026
 * Vertical Order Traversal Of Binary Tree: HARD
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;

        if (!root) return result;

        //.. map of col : [row, val]
        //.. we will use this to keep the column sorted
        //.. why? coz that's what we need, lol
        unordered_map<int, vector<pair<int, int>>> colMap;

        // BFS
        // {node, row, col}
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();

            colMap[col].push_back({row, node->val});

            if (node->left) {
                q.push({node->left, row + 1, col - 1});
            }

            if (node->right) {
                q.push({node->right, row + 1, col + 1});
            }
        }

        //.. now for the most interesting part
        //.. build result from colMap

        for (auto& [col, vec]: colMap) {
            // sort by row
            sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first == b.first) {
                    return a.second < b.second;  // same row: sort by value
                }
                return a.first < b.first;  // different row: sort by row
            });

            vector<int> colValues;
            for (auto& [row, val] : vec) {
                colValues.push_back(val);
            }
            result.push_back(colValues);
        }

        return result;
    }
};