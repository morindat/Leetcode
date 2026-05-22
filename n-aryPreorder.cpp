# include <stack>
# include <vector>
using namespace std;

/**
 * Problem 136
 * Problem 23/45 of May 2026
 * N-ary Tree Preorder: EASY
 * Date: 22/05/26
 * Time Complexity: O(n);
 */

class Node {
public:
    int val;
    vector<Node*> children;

    Node () {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
private:
    vector<int> res;
    
    void dfs(Node* root) {
        if (!root) return;

        // push the current node
        res.push_back(root->val);

        // visits its children
        for (Node* child : root->children) {
            dfs(child);
        }
    }
public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return res;
    }
};

// Iterative Version
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        
        vector<int> result;
        stack<pair<Node*, int>> st;  // {node, next_child_index}
        st.push({root, 0});
        
        while (!st.empty()) {
            auto& [node, idx] = st.top();
            
            if (idx == 0) {
                // First time visiting this node
                result.push_back(node->val);
            }
            
            if (idx < node->children.size()) {
                // Process next child
                st.push({node->children[idx], 0});
                idx++;
            } else {
                // All children processed
                st.pop();
            }
        }
        
        return result;
    }
};