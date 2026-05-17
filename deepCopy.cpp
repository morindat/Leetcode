# include <unordered_map>

// Problem 17
// Copy List With Random Pointers: MEDIUM
// Date: 17/01/26

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val){
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        std::unordered_map<Node*, Node*> mp;

        // Pass 1: create copies
        Node* curr = head;
        while (curr) {
            mp[curr] = new Node(curr->val); 
            curr = curr->next;
        }

        // Pass 2: assign next and random
        curr = head;
        while (curr) {
            mp[curr]->next = curr->next ? mp[curr->next] : nullptr;
            mp[curr]->random = curr->random ? mp[curr->random] : nullptr;
            curr = curr->next;
        }

        return mp[head];
    }
};
