# include <stack>

// Problem 18
// Flatten Multilevel Doubly Linked List: MEDIUM
// Date: 18/01/26

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node dummy;
        dummy.val = 0;
        dummy.next = nullptr;
        dummy.prev =  nullptr;
        dummy.child = nullptr;

        Node* current = &dummy;
        std::stack<Node*> st;
        st.push(head);

        while (!st.empty()){
            Node* temp = st.top();
            st.pop();

            if (temp->next) st.push(temp->next);
            if (temp->child) st.push (temp->child);

            current->next = temp;
            temp->prev = current;
            temp->child = nullptr;
            current = temp;
        }

        Node* realHead = dummy.next;
        realHead->prev = nullptr;

        return realHead;
    }
};