#include <iostream>

// Problem 09
// Partition Linked List: MEDIUM
// Date: 09/01/26


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // create two dummy nodes 
        // one for less list and one for greater list
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;

        // loop once
        // every element less than x put in less
        // and everything else put em in greater
        while (head){
            if (head->val < x){
                less->next = head;
                less = less->next;
            } else if (head->val >= x){
                greater->next = head;
                greater = greater->next;
            }

            head = head->next;
        }

        // add null terminator on the greater list and connect with the less list
        greater->next = nullptr;
        less->next = greaterDummy.next;

        // return the less list head
        return lessDummy.next;
    }

};