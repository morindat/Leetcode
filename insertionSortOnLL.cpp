# include <iostream>
using namespace std;

// Problem 10
// Insertion Sort on Linked List: MEDIUM
// Date: 10/01/26



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        while (head){
            ListNode* current = head;
            head = head->next;

            ListNode* prev = &dummy;
            while (prev->next && prev->next->val < current->val){
                prev = prev->next;
            }

            current->next = prev->next;
            prev->next = current;
        }

        return dummy.next;
    }
};