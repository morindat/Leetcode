# include <queue>
# include <string>
# include <sstream>
using namespace std;

/**
 * Problem 126
 * Problem 13/45 of May 2026
 * Serialize And Deserialize Binary Tree: HARD
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

class CodecDFS {
private:

public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        // init an empty string 
        string result;

        // bfs queue and push in the root
        queue<TreeNode*> q;
        q.push(root);

        // normal bfs logic
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // as long as a node has something, push in both left and right children
            // regardless of whether or not they are null
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }

            else {
                result += "null,";
            }
        }

        return result;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string item;

        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(ss, item, ',')) {
                if (item != "null") {
                    node->left = new TreeNode(stoi(item));
                    q.push(node->left);
                }
            }

            if (getline(ss, item, ',')) {
                if (item != "null") {
                    node->right = new TreeNode(stoi(item));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

class CodecDFS {
private:
    TreeNode* buildTree(stringstream& ss) {
        string val;
        getline(ss, val, ',');

        if (val == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
        
        return node;
    }

public:
    string serialize(TreeNode* root) {
        if (!root) return "null";

        return to_string(root->val) + "," + 
                serialize(root->left) + "," +
                serialize(root->right);

    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
    }
};