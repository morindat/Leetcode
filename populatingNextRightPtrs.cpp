# include <vector>
# include <queue>
# include <unordered_map>
using namespace std;

// Problem 113
// Problem 22 of April
// Populating Next Right Pointers in Each Node: MEDIUM
// Date: 25/04/26
// Complexity: O(n)

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (!root) return nullptr;

    Node* curr = root;

    while (curr) {
        Node dummy;           // sentinel for next level's list
        Node* tail = &dummy;  // tail of next level's linked list

        // Walk across current level using next pointers
        while (curr) {
            if (curr->left) {
                tail->next = curr->left;
                tail = tail->next;
            }
            if (curr->right) {
                tail->next = curr->right;
                tail = tail->next;
            }
            curr = curr->next; // move right on current level
        }

        // Drop down to next level
        curr = dummy.next;
    }

    return root;
}

Node* connect(Node* root) {
    if (!root) return nullptr;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size(); // nodes at current level
        for (int i = 0; i < sz; i++) {
            Node* node = q.front(); q.pop();
            // link to next node in queue (same level)
            if (i < sz - 1)
                node->next = q.front();
                
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return root;
}