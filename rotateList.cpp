#include <iostream>

// Problem 08
// Rotate Linked List: MEDIUM
// Date: 08/01/26

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateList(ListNode* head, int k){
        // edge cases
        if (!head || !head->next) return head;

        // find length and tail
        int len = 1;
        ListNode* temp = head;

        while (temp->next){
            temp = temp->next;
            len++;
        }

        // make circular
        temp->next = head; 

        // mod k since k can be very large and we do not want that
        k = k % len;
        if (k == 0){
            temp->next = nullptr;
            return head;
        }

        // now we need to know the tail of the new list
        int steps = len - k - 1;
        ListNode* temps = head;

        for (int i = 0; i < steps; i++){
            temps = temps->next;
        }

        // new head is a node after the tail, break the tail after storing new head
        ListNode* newHead = temps->next;
        temps->next = nullptr;

        return newHead;
    }
};
