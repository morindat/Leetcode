#include <sstream>
# include <string>
# include <queue>
# include <fstream>
using namespace std;

/**
 * Problem 138
 * Problem 25/45 of May 2026
 * Serialize And Deserialize BST: MEDIUM
 * Date: 23/05/26
 * Time Complexity: O(n);
 * The solution is literally the same to the problem 126 on this series
 * Titled serializeAndDeserialize.cpp
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);
        string result = "";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }

            else {
                result += "#,";
            }
        }
        return result;
    }

    TreeNode* deserialize (string word) {
        if (word.empty()) return nullptr;

        stringstream ss(word);
        string data;
        getline(ss, data, ',');

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(data));
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (getline(ss, data, ',')) {
                if (data != "#") {
                    node->left = new TreeNode(stoi(data));
                    q.push(node->left);
                }
            }

            // Right child
            if (getline(ss, data, ',')) {
                if (data != "#") {
                    node->right = new TreeNode(stoi(data));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};